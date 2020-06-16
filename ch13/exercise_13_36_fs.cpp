#include <string>
#include <set>

class Folder
{
    friend class Message;
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    void add_to_Message(const Folder& f);
    void remove_from_Message();
    ~Folder()
    {
        remove_from_Message();
    }

private:
    std::set<Message*> messages;
    void addMsg(Message& m)
    {
        messages.insert(&m);
    }
    void deleteMsg(Message& m)
    {
        messages.erase(&m);
    }
};

// Folders实现
/////////////////////////////////////////////////////
Folder::Folder(const Folder& f) :
    messages(f.messages)
{}

Folder& Folder::operator=(const Folder& rhs)
{
    messages = rhs.messages;
}

// 当folder中加入一条message时
// 要考虑到该message的每条复制都要加入该folder维护的message列表中
void Folder::add_to_Message(const Folder& f)
{
    for (auto m : f.messages)
        m->add_to_Folders(f);
}

void Folder::remove_from_Message()
{
    for (auto m : messages)
        m->remove_from_Folders();
}

class Message {
    friend class Folder;
    explicit Message(const std::string str = "") :
        contents(str) {}

    Message(const Message&);
    Message& operator=(const Message& rhs)
    {
        // 首先调用remove_from_Folders()防止出现自我赋值
        remove_from_Folders();
        contents = rhs.contents;
        folders = rhs.folders;
        add_to_Folders(rhs);
        return *this;
    }

    ~Message()
    {
        remove_from_Folders();
    }

    // 从给定Folder集合中添加/删除本Message
    void Save(Folder&);
    void remove(Folder&);

private:
    std::string contents;
    std::set<Folder*> folders;  // 维护一个folders的集合， 保存当前message存在的folders成员

    // 私有工具函数
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};

Message::Message(const Message& m) :
    contents(m.contents), folders(m.folders)
{
    // 对于Message的拷贝来说，得到的副本应该与原Message出现在相同的Folder中
    add_to_Folders(m);
}

void Message::Save(Folder& f)
{
    folders.insert(&f);  // 将给定Folder添加到我们的Folder列表中
    f.addMsg(this);      // 将本Message添加到f的Message集合中
}

void Message::remove(Folder& f)
{
    folders.erase(&f); // 从我们的Folder列表中删去本folder
    f.deleteMsg(this);
}


void Message::add_to_Folders(const Message& m)
{
    // 对每个包含m的Folder
    // 向该Folder添加一个指向本Message的指针
    for (auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->deleteMsg(this);
}