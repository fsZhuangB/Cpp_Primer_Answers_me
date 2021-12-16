## 13.2
必须传入rhs的引用，而不是rhs的值
## 13.3

## 13.5
```c++
class HasPtr {
public:
    HasPtr(const string& s = string()) : ps(new string(s)), i(0) { }
    HasPtr(HasPtr& hp) {
        string* newString = new string(*hp.ps);
        this->ps = newString;
        this->i = hp.i;
    }
private:
    string* ps;
    int i;
};
```
## 13.6

## 13.8
```c++
    HasPtr& operator= (const HasPtr& rhs)
    {
        // 记得处理自赋值
        if (this== rhs)
            return *this;

        this->i = rhs.i;
        // 分配新空间
        string* newString = new string(*rhs.ps);
        // 要记得释放原来的ps的位置的空间资源
        delete this->ps;
        this->ps = newString;
        return *this;
    }
```

## 13.11
```C++
    ~HasPtr() {
        delete ps;
    }
```

## 13.14
三个数字是相同的，因为没有拷贝构造函数，所以mysn被单纯的赋值了。
```C++
class number {
public:
    number() {
        mysn = unique++;
    }
    int mysn;
    static int unique;
};
int number::unique = 10;

void f(number s)
{
    std::cout << s.mysn << std::endl;
}
```

## 13.15
定义了拷贝构造函数之后，变成了三个不同的数字。
```C++
class numbered {
public:
    numbered() {
        mysn = unique++;
    }

    numbered(const numbered& n) {
        mysn = unique++;
    }

    int mysn;
    static int unique;
};
## 13.16
如果传入的参数为引用，那么将不会有拷贝赋值的操作，所以不会变化

```c++
class numbered {
public:
    numbered() {
        mysn = unique++;
    }
    int mysn;
    static int unique;
};

int numbered::unique = 10;

void f(numbered s) {
    std::cout << s.mysn << std::endl;
}
```

## 13.23
在编写拷贝赋值运算符时，要注意两点：
1. 防止自赋值，一个好的方法时在销毁左侧运算符对象之前拷贝右侧运算符对象。
2. 大多数赋值运算符结合了析构函数和拷贝构造函数的工作。

## 13.24
会发生内存泄露。
在下面这种情况下，会发生为定义的情况：
```c++
HasPtr f(HasPtr hp)
{
  HasPtr ret = hp;
  return ret;
}
// ret和hp被销毁，一个指针被销毁两次
```

## 13.27
```C++
class HasPtr {
public:
    HasPtr(const string& s = string()) : ps(new string(s)), i(new int(1)) { }
    HasPtr(HasPtr& hp) : ps(hp.ps), i(hp.i){
        // 将该对象的引用计数指针指向被拷贝对象的引用计数所指向的位置
        // 将引用计数加1
        ++*i;
    }
    // 递增右侧，递减左侧
    HasPtr& operator= (HasPtr& rhs)
    {
        ++*rhs.i;
        // 递减被赋值对象的引用计数
        if (--*i == 0)
        {
            delete ps;
            delete i;
        }
        ps = rhs.ps;
        i = rhs.i;
        return *this;
    }
    ~HasPtr() {
        // 可以将(*i)--优化一下
        if (--*i == 0)
        {
            delete ps;
            delete i;
        }
    }
private:
    // 共享的内存区域
    string* ps;
    // 引用计数
    int* i;
};
```
## Exercise 13.35:
What would happen if Message used the synthesized versions of the copy-control members?
some existing Folders will out of 'sync' with the Message after assignment.

