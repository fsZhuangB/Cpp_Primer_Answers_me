#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;
bool isShorter(const string& s1, const string& s2)
{
    return s1.size() < s2.size();
}
int main()
{
    string a;
    vector<string> v={"hi", "red", "hi", "test", "goooood" ,"uuu", "red" ,"goooood" };
    // while (cin >> a)
    // {
    //     v.push_back(a);
    // }

    for (auto& s : v)
    {
        cout << s << " ";
    }
    cout << "\n";
    sort(v.begin(), v.end());
    auto end_unique = unique(v.begin(), v.end());
    v.erase(end_unique, v.end());
    stable_sort(v.begin(), v.end(), isShorter);
    for (auto& s : v)
    {
        cout << s << " ";
    }
    cout << "\n";
}