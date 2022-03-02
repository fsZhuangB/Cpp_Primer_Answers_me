#include <iostream>
using namespace std;
class A {
    private: 
    int a = 1;
    public:
    virtual int get() { return a;}
};

class B : public A {
    int b = 2;
        public:

    virtual int get() { return b; }
};

class C : public B {
    int c = 3;
        public:

    virtual int get() { return c; }
};
class D : public B, public A{
    int d = 4;
        public:

    virtual int get() { return d; }
};
int main()
{
    // 使用基类的引用或者指针调用一个虚成员函数会执行动态绑定
    A *pa = new C;
    cout << pa->get() << endl;
    B *pb = dynamic_cast<B*>(pa);
    if (B* pb = dynamic_cast<B*>(pa))
    {
        cout << pb->get() << endl;
    }
    else
    {
        cout << "bad\n";
    }
}