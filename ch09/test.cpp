#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <array>
#include <list>
using namespace std;

int main()
{
    list<string> lst;
    string word;
    auto iter = lst.begin();
    while (cin >> word)
        iter = lst.insert(iter, word);
    for (auto i : lst)
        cout << i;
    return 0;
}