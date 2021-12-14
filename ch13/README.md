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
## Exercise 13.35:
What would happen if Message used the synthesized versions of the copy-control members?
some existing Folders will out of 'sync' with the Message after assignment.

