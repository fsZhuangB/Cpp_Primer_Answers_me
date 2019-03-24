#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <exception>

class StrBlob
{
    public:
    typedef  std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const {return data->empty(); }

    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back() const { check(0, "It's empty!"); return data->pop_back(); }
    std::string& front() const { check(0, "It's empty!"); return data->front(); }
    std::string& back() const { check(0, "It's empty!"); return data->back(); }


    private:
    std::shared_ptr<std::vector<std::string>> data = std::make_shared<std::vector<std::string>>();
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il):
                data(std::make_shared<std::vector<std::string>>(il)) { }

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= this->size())
        throw std::out_of_range(msg);
}

int main()
{
    StrBlob b1;
    StrBlob b2{"what", "it", "is"};

    return 0;
}
