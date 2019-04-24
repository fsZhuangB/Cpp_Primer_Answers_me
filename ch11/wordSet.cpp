#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But", "And", "the", "but", "and"};
    string word;
    while (cin >> word)
        if (exclude.find(word) == exclude.end())
            ++word_count[word];
    for (const auto &w:word_count)
        cout << w.first << " " << w.second << endl;

    return 0;
}