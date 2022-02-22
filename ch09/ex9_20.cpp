#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <list>
using namespace std;
int main()
{
    list<int> mylist{1,2,3,4,5,6,7,8};
    deque<int> odd;
    deque<int> even;

    for (auto beg = mylist.begin(); beg != mylist.end(); ++beg)
    {
        if (*beg % 2 == 0)
        {
            even.emplace_back(*beg);
        }
        else
        {
            odd.emplace_back(*beg);
        }
    } 

    for (auto& o : odd)
    {
        cout << o << " ";
    }
    cout << "\n";
    for (auto& o : even)
    {
        cout << o << " ";
    }

}