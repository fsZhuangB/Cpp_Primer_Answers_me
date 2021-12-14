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
## Exercise 13.35:
What would happen if Message used the synthesized versions of the copy-control members?
some existing Folders will out of 'sync' with the Message after assignment.

