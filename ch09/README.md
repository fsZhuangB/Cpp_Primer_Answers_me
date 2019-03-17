# 我自己的练习作业

## 练习9.1
* (a) 单词数量是固定的，但是需要排序操作，为了最小化排序时的插入元素所带来的额外开销，在此建议使用`list`或者`forward_list`。
* (b) 因为仅仅在头尾进行插入和删除的操作，所以应该选择`deque`容器。
* (c) 该操作分为两个部分：
1. 从文件中将未知数量的整数读取进来
2. 排序时进行的读取和插入操作
3. 总体来看，读取操作更多，使用'vector'可能是更好的选择。

## 练习9.2
```cpp
std::list<std::deque<int>> mylist;
```

## 练习9.3
两个迭代器`begin`和`end`需要满足以下条件
- 它们指向同一个容器中的元素，或者是容器最后一个元素之后的位置。
- 我们可以通过反复递增`begin`来到达`end`。或句话说，`end`不应该在`begin`之前。

## 练习9.4
[源代码](https://github.com/fsZhuangB/Cpp_Primer_Answers/blob/master/ch09/exercise9_4_fs.cpp) 

## 练习9.5
```cpp
int find(std::vector<int>::iterator begin, std::vector<int>::iterator end, int val)
{
    while (begin != end)
    {
        if (*begin == val)
        {
            return val;
            break;
        }
        begin++;    
    }
    return false;
}
```

## 练习9.6

`while (iter1 < iter2)` 这句话有错误，迭代器拥有迭代器范围，应该改成`while (iter1 != iter2)`

## 练习9.7
```cpp
vector<int>::size_type;
```

## 练习9.8
```cpp
list<string> const_iterator;  // 读
list<string> iterator;        // 写
```

## 练习9.9
`begin`是普通迭代器，而`cbegin`是`const`类型的迭代器

## 练习9.10
```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```
以上这段代码在clang++(MacOS X version 10+)中会报错:
```cpp
exercise9_10_fs.cpp:9:5: error: 'auto' deduced as 'std::__1::__wrap_iter<int *>' in declaration of 'it1' and deduced as 'std::__1::__wrap_iter<const int *>'
      in declaration of 'it2'
    auto it1 = v1.begin(), it2 = v2.begin();
```
大概意思就是说`auto`这个隐式转换符号将it1推导为`std::__1::__wrap_iter<int *>`类型，但是将it2推导为`std::__1::__wrap_iter<const int *>`类型，`auto`必须始终推导为同一类型。所以我们将代码改为:
```cpp
    vector<int> v1;
    const vector<int> v2;

    auto it1 = v1.begin();
    auto it2 = v2.begin();
    auto it3 = v1.cbegin(), it4 = v2.cbegin();
```
这样就不会报错了。
`it1`是`vector<int>::iterator`
`it2`、`it3`、`it4`是`vector<int>::const_iterator`

## 练习9.11
```cpp
#include <vector>
#include <string>
/* 默认构造函数，初始化一个空的int类型的vector */
vector<int> v1;  

/* 拷贝初始化，v2初始化为v1的拷贝 */
vector<int> v2(v1);
vector<int> v2 = v1;

/* 列表初始化 */
/* vector初始化为列表中string元素的拷贝 */
vector<string> v3{ "foo", "bar", "good" };
vector<string> v3 = { "foo", "bar", "good" };

/* 迭代器范围初始化 */
vector<string>::iterator b = v3.begin();
vector<string>::iterator e = v3.end();
// v4 初始化为迭代器b, e中范围的拷贝
vector<string> v4(b, e); 
// v5将const char*元素转换为string
vector<const char*> v5(b, e);

/* 值初始化 */
// 将vector大小初始化为10
vector<int> v6(10);

// 将vector初始化为10个值为"foo"的元素
vector<string> v7(10, "foo")
```

## 练习9.12
- 对于接受一个容器创建其拷贝的构造函数，其容器类型和元素类型必须都要相同
- 对于接受两个迭代器创建拷贝的构造函数，其容器类型和元素类型可以不同，但是元素类型必须能够进行类型转换

## 练习9.13
```cpp
list<int> ilst(5, 4);
vector<int> ivc(5, 5);

vector<double> dvc(ilst.begin(), ilst.end());
vector<double> dvc2(ivc.begin(), ivc.end());
```

## 练习9.14
```cpp
list<const char*> l{"foo", "bar"};
vector<string> v;
v.assign(l.cbegin(), l.cend());
```
