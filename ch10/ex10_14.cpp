#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;

int main()
{
    auto f = [](const int a, const int b){ return a + b;};
    cout << f(1,2) << endl;
    
}