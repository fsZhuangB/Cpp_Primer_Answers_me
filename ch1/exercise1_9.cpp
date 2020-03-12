#include <iostream>
int main()
{
    int sum = 0, val = 50; // or sum = 50, val = 51
    while (val <= 100)
    {
        sum += val;
        ++val;
    }
    std::cout << sum << std::endl;
}