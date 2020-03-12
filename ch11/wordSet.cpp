#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i)
    {
        ivec.push_back(i);
        ivec.push_back(i);  // 每个数重复保持一次
    }

    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());
    cout << ivec.size() << endl;
    cout << iset.size() << endl;
    cout << miset.size() << endl;
}