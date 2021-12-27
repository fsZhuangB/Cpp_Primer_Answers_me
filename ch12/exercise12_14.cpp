#include <iostream>
#include <memory>
#include <string>
using namespace std;
struct dest
{
    string ip;
    int port;
    dest(string ip, int port) : ip(ip), port(port) {}  
};
// 连接所需信息
struct con  
{
    string ip;
    int port;
    con(string ip, int port) : ip(ip), port(port) {}  
};

// 打开连接
con connect(dest* destination)
{
    // 不要用裸指针，而是shared_ptr
    shared_ptr<con> newCon(new con(destination->ip, destination->port));
    std::cout << "creating connection(" << newCon.use_count() << ")" << std::endl;
    return *newCon;
}
// 关闭连接
void discon(con newCon)
{
    std::cout << "connection close(" << newCon.ip << ":" << newCon.port << ")" << std::endl;
}

void end_connection(con *p)
{
	discon(*p);
}

void f(dest &d)
{
	con c = connect(&d);
	shared_ptr<con> p(&c, end_connection);
}

int main()
{
    dest d("123.123.123.111", 1010);
    f(d);

    return 0;
}