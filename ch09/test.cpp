#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <array>
#include <list>
using namespace std;

int main()
{
    // 将const char*转换为string
    list<string> names;
    vector<const char*> v {"hi", "jack"};;
    names.assign(v.begin(), v.end());

    for (auto& s : names)
    {
        cout << s << " ";
    }

    return 0;
}