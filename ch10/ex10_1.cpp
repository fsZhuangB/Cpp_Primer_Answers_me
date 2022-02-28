#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int a;
    vector<int> v;
    while (cin >> a)
    {
        v.push_back(a);
    }

    int tar = 10;
    cout << "the target has:" << count(v.cbegin(), v.cend(), tar) << "times" << endl;
}