#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string s = "abc,efd,opq";
    auto it = find(s.rbegin(), s.rend(), ',');
    cout << string(it.base(), s.end()) << endl;
}