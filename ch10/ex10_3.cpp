#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
int main()
{
    int a;
    vector<int> v;
    while (cin >> a)
    {
        v.push_back(a);
    }

    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "the sum is:" << sum  << endl;
}