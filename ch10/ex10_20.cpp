#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;

int main()
{
    string a;
    vector<string> v={"hi", "red", "hi", "test", "goooood" ,"uuu", "red" ,"goooood" };
    int sz;
    cin >> sz;
    int count = count_if(v.begin(), v.end(), [sz](const string& s){ return s.size() >= sz;});
    cout << "There're " << count << endl;
}