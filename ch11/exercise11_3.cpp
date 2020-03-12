#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    map<string, size_t> word_count;
    while (cin >> word)
        ++word_count[word];
    for (const auto &w:word_count)
        cout << w.first << w.second << endl;
}