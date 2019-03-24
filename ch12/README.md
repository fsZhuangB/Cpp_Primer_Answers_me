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
