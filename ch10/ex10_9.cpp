#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;
int main()
{
    string a;
    vector<string> v;
    while (cin >> a)
    {
        v.push_back(a);
    }

    for (auto& s : v)
    {
        cout << s << " ";
    }
    cout << "\n";
    sort(v.begin(), v.end());
    auto end_unique = unique(v.begin(), v.end());
    v.erase(end_unique, v.end());
    for (auto& s : v)
    {
        cout << s << " ";
    }
    cout << "\n";
}