#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <array>
#include <list>
using namespace std;

int main()
{
    int some_value = 4;
    vector<int> iv{1, 4, 4, 9, 4, 5, 4};

    vector<int>::iterator iter = iv.begin(),
                          mid = iv.begin() + iv.size() / 2;
    while (iter != mid)
    {
        if (*iter == some_value)
        {
            iter = iv.insert(iter, 2 * some_value);
            ++iter;
        }
        ++iter;
        mid = iv.begin() + iv.size() / 2;

    }
    for (auto& v : iv)
    {
        cout << v << " ";
    }
    return 0;
}