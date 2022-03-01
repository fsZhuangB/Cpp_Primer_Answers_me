#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;
bool hasFive(const string& s)
{
    return s.size() >= 5;
}
int main()
{
    vector<string> words={"hi", "red", "hi", "testts", "goooood" ,"uuuuu", "red" ,"goooood" };
    auto end_true = partition(words.begin(), words.end(), hasFive);
    for (auto beg = words.begin(); beg != end_true; ++beg)
    {
        cout << *beg << " ";
    }
}