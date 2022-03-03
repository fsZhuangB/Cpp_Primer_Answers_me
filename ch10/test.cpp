#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <numeric>
#include <functional>
using namespace std;
bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}
int main()
{
    vector<string> a{"a", "bb", "ccc"};
    int sz = 1;
    auto it = find_if(a.begin(), a.end(), [sz](const string& s){ return s.size() >= sz;});
    auto check6 = bind(check_size, std::placeholders::_1, sz);
    auto it2 = find_if(a.begin(), a.end(), check6);
    cout << a.end() - it2;


    
}