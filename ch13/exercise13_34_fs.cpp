#include <string>
#include <set>
class Folder;
class Message {
	friend class Folder;
public:
	// folder is implicitly initialized to the empty set
	explicit Message(const std::string& str = "") :
		contents(str) { }
	// 拷贝控制成员，用来管理指向本Message的指针
	Message(const Message& m) : 
		contents(m.contents), folders(m.folders)
	{
		add_to_Folders(m);  // 将本消息添加到指向m的Folder中
	}
	Message& operator=(const Message& rhs)
	{
		remove_from_Folders();   // 更新已有的Folder
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
	void save(Folder&);
	void remove(Folder&);

private:
	std::string contents;      // 保存文本信息
	std::set<Folder*> folders; // 保存指向本Mesasge所在的Folder的指针，也就是Message的位置

	// 拷贝赋值运算符通常执行拷贝构造函数和析构函数中也要完成的工作
	// 公共的工作应该放在private的工具函数中完成
	
	// 将本Message添加到指向参数的Folder中
	void add_to_Folders(const Message& m)
	{
		for (auto f : m.folders)
			f->addMsg(this);
	}
	// 从folders中的每个Folder中删除本Message
	void remove_from_Folders()
	{
		for (auto f : folders)
			f->remMsg(this);
	}

}; 

void Message::save(Folder& f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder& f)
{
	folders.erase(&f);
	f.remMsg(this);
}