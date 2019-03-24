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

