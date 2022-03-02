#include<iostream>
#include<string>
#include<typeinfo>
#include<assert.h>
using namespace std;
class Father
{
public:
	Father() {}
    virtual void test()
    {
        cout << "This is Father's test()\n";
    }
	virtual ~Father() { cout << "delete  Father" << endl; }
};
class Son : public Father
{
public:
	Son() {}
    void test() override
    {
        cout << "This is Son's test()\n";
    }
	virtual ~Son() { cout << "delete  Son" << endl; }
};
//新增的，我们需要新增foo函数，但在基类中没有foo虚函数
class Grandson:public Son
{
public:
	Grandson() {}
	virtual ~Grandson(){ cout << "delete Grandson" << endl; }
public:
	//新增加的函数foo
	void foo()
	{
		cout << "Grandson's foo" << endl;
	}
};
int main()
{
	Father *f = new Grandson;
	//f->foo();	//error：“Father”没有成员foo。
	delete f;

	//使用dynamic_cast运算符进行转换，便可以通过基类对象指针f2操作派生类Grandson的非虚函数foo
	Father* f2 = new Grandson;
	Grandson* d_c_f2 = dynamic_cast<Grandson*>(f2);
	assert(d_c_f2 != nullptr);  //违背断言，阻止下一行操作
	d_c_f2->foo();	//打印Grandson's foo
	delete f2;

    // 多态测试
    Father* f3 = new Son;
    f3->test();
	return 0;
}