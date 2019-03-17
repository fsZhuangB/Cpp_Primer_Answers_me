#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <list>
using namespace std;

int main()
{
    list<int> list1{1, 2, 3, 4, 5, 6};
    vector<int> vector2{1, 2, 3, 4, 5, 6};
    auto b = list1.begin();
    auto e = list1.end();

    auto b2 = vector2.begin();
    auto e2 = vector2.end();
    vector<double> vector1(b, e);
    vector<double> vector3(b2, e2);
    for (auto i:vector1)
        cout << i << ", ";
    cout << endl;

for (auto i:vector3)
        cout << i << ", ";
    cout << endl;
    return 0;

}