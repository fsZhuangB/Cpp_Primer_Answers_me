#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

int main()
{
    shared_ptr<int> p3 = make_shared<int>(42);

    shared_ptr<string> p4 = make_shared<string>("dsa");

    shared_ptr<string> p5 = make_shared<string>();

    auto p6 = make_shared<vector<string>>();

    auto p = make_shared<int>(42);
    auto q(p);

    vector<string> v1;
    {
        vector<string> v2 = {"an", "a", "the"};
        v1 = v2;
    }

}