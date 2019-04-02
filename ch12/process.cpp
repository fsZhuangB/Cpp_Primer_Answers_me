#include <memory>
using namespace std;

void process(shared_ptr<int> ptr)
{
    *ptr = 42;
}

int main()
{
    shared_ptr<int> p(new int(43));  // 引用计数为1
    int *x = new int(1024);
    shared_ptr<int> p2;
    process(p2);
    int i = *p;

    // p2是一个空悬指针！
    int j = *p2;

    return 0;
}