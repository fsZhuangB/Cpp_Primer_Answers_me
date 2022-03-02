#include <iostream>
using namespace std;
constexpr int size()
{
    return 5;
}
int main()
{
    constexpr int mf = 20;
    constexpr int limit = mf + 1;
    constexpr int sz = size();
    cout << sz << endl;

    const int ci = 42;
    const int *p2 = &ci;
    const int &p = ci;
    cout << p << endl;

    static constexpr int x = 42;
    const int *const p3 = &ci;
    constexpr const int *p4 = &x;
    static int j = 0;
    constexpr int *p5 = &j;
    cout << *p4 << endl;
    return 0;
}