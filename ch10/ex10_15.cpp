#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;

int getNum(int n)
{
    auto f = [n](int num) {
        return n+num;
    };
    return f(10);
}
int main()
{
    int n;
    cin >> n;
    cout << getNum(n) << endl;
    
}