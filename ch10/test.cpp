#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <numeric>
using namespace std;
int main()
{
    string a;
    vector<string> v;
    while (cin >> a)
    {
        v.push_back(a);
    }
    string sum = accumulate(v.begin(), v.end(), string(""));
    cout << sum << endl;

    
}