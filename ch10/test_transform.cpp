#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;

int main()
{
    vector<int> a{1,-1,2,-2,3,4,-3};
    transform(a.begin(), a.end(), a.begin(), [](int i){return i > 0 ? i : -i; });
    for_each(a.begin(), a.end(), [](int i){ cout << i << " ";});

}