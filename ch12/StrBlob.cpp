#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
#include <exception>
// using namespace std;

class StrBlob
{
    public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    std::string& front();
    std::string& back();

    void push_back(const std::string &t) {data->push_back(t); }
    void pop_back();

    private:
    std::shared_ptr<std::vector<std::string>> data;
    // if data[i] illegal, it'll throw an except
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il):
                data(std::make_shared<std::vector<std::string>>(il)) { }

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

std::string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

int main()
{
    int * pi = new int;
    std::string *ps = new std::string(10, '9');  // 此处要使用''
    std::vector<int> *pv = new std::vector<int>{0, 1, 2, 3, 4, 5};

    auto p1 = new auto(20);
    auto p2 = new auto("good");
    const int *pci = new const int(1024);

}

