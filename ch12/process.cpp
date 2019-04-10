#include <memory>
#include <iostream>
using namespace std;

void process(shared_ptr<int> ptr)
{
    // *ptr = 42;
    cout << *ptr << endl;
}

int main()
{
    shared_ptr<int> p(new int(42));  // 引用计数为1
    int *q = p.get();								 // 正确：但使用q时要注意，不要让它管理的指针被释放
    {
        shared_ptr<int>(q); 						 // 未定义：两个独立的shared_ptr指向相同的内存
    }																 // 程序块结束，q被销毁，它指向的内存被释放了
    int foo = *p;
  
    return 0;
}