#include <memory>
#include <iostream>
using namespace std;

void process(shared_ptr<int> ptr)
{
    *ptr = 42;
    cout << *ptr << endl;
}

int main()
{
    auto p = new int();
    auto sp = make_shared<int>();
    process(shared_ptr<int>(p));
    int *foo = p;
    cout << *foo << endl;
  
    return 0;
}