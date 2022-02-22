#include <vector>
#include <string>
#include <iostream>
#include <deque>
using namespace std;
int main()
{
    string s;
    deque<string> mydeque;
    while (cin >> s)
    {
        mydeque.emplace_back(s);
    }

    for (auto beg = mydeque.begin(); beg != mydeque.end(); ++beg)
    {
        cout << * beg << " ";
    } 

}