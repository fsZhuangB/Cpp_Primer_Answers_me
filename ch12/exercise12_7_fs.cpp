#include <memory>
#include <vector>
#include <iostream>

void read_stdin(std::shared_ptr<std::vector<int>> v);
void print_in(std::shared_ptr<std::vector<int>> v);

int main()
{
    std::shared_ptr<std::vector<int>> pv(new std::vector<int>());
    read_stdin(pv);
    print_in(pv);

    return 0;
}

void read_stdin(std::shared_ptr<std::vector<int>> v)
{
    int buffer;
    while (std::cin >> buffer)
        (*v).push_back(buffer);
}

void print_in(std::shared_ptr<std::vector<int>> v)
{
    for (auto i : *v)
        std::cout << i << " ";
    std::cout << std::endl;
}