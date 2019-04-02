# 我自己的练习作业

## 练习12.1
> 在此代码的结尾，b1 和 b2 各包含多少个元素？
```cpp
StrBlob b1;
{
	StrBlob b2 = {"a", "an", "the"};
	b1 = b2;
	b2.push_back("about");
}
```
b1、b2实际操作的是同一个vector，b1有4个元素，但在这段代码的末尾，b2被销毁，不影响b1中的元素

## 练习12.2
> 编写你自己的StrBlob 类，包含const 版本的 front 和 back。
见习题

## 练习12.3

> StrBlob 需要const 版本的push_back 和 pop_back吗？如需要，添加进去。否则，解释为什么不需要。

不需要。`push_back` 和 `pop_back` 会改变对象的内容。而 const 对象是只读的，因此不需要。

## 练习12.4

> 在我们的 check 函数中，没有检查 i 是否大于0。为什么可以忽略这个检查？

`size_type`是一个无符号整数类型，当我们传入值小于0时，会自动转化为一个正整数。

## 练习12.6
> 编写函数，返回一个动态分配的 int 的vector。将此vector 传递给另一个函数，这个函数读取标准输入，将读入的值保存在 vector 元素中。再将vector传递给另一个函数，打印读入的值。记得在恰当的时刻delete vector。

## 练习12.7
> 重做上一题，这次使用 shared_ptr 而不是内置指针。

## 练习12.8

> 下面的函数是否有错误？如果有，解释错误原因。
```cpp
bool b() {
	int* p = new int;
	// ...
	return p;
}
```
有错误，返回的指针会被隐式地转换为`bool`类型，导致p指向的内存无法被释放，会导致内存泄露(memory leakage)

## 练习12.9

> 解释下面代码执行的结果。
```cpp
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```
r 和 q 指向 42，而之前 r 指向的100的内存空间并没有被释放，因此会发生内存泄漏。r2 和 q2 都是智能指针，当对象空间不被引用的时候会自动释放。

## 练习12.10

> 下面的代码调用了第413页中定义的process 函数，解释此调用是否正确。如果不正确，应如何修改？
```cpp
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
```

正确的。process的参数是传值方式传递的，因此实参会被拷贝到其接收的ptr中。拷贝一个`shared_ptr`会递增其引用计数，因此在process运行过程中，引用计数值至少为2。当process结束时，ptr的引用计数会递减，但不会变为0.因此当局部变量ptr被销毁时，ptr指向的内存不会被释放。

