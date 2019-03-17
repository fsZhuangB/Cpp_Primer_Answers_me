#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <array>
#include <list>
using namespace std;

int main()
{

    vector<const char*> oldstyle{"foo", "bar"};
    list<string> names;
    oldstyle.assign(names.cbegin(), names.cend());

    return 0;
}