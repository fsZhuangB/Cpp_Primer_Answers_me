#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <list>
using namespace std;
int main()
{
    string s;
    list<string> mylist;
    while (cin >> s)
    {
        mylist.emplace_back(s);
    }

    for (auto beg = mylist.begin(); beg != mylist.end(); ++beg)
    {
        cout << * beg << " ";
    } 

}