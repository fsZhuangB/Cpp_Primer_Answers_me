// cpp_primer_5th
// exercise9_4_fs.cpp
#include <iostream>
#include <vector>
using namespace std;
bool find(std::vector<int>::iterator, std::vector<int>::iterator, int);

int main()
{
    std::vector<int> myVec = {1, 2, 3, 4, 5, 6};
    std::vector<int>::iterator beg = myVec.begin();
    std::vector<int>::iterator end = myVec.end();
    auto it = std::find(beg, end, 7);
    if (it == myVec.end())
    {
        cout << "not find" << endl;
    }
    else
    {
        cout << *it << endl;
    }


    return 0;
}

bool find(std::vector<int>::iterator begin, std::vector<int>::iterator end, int val)
{
    while (begin != end)
    {
        if (*begin == val)
        {
            return true;
        }
        begin++;    
    }
    return false;
}