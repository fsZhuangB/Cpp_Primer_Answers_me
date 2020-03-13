#include <iostream>
using namespace std;
int main()
{
    int i = 42;
    int &r1 = i;      // 普通的引用
    const int &r2 = i;// 对常量引用
    r1 = 0;

    cout << "i = " << i << endl;
    

    return 0;
}