#include <map>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class solution
{
    public:
    map<string, size_t> countWord()
    {
        map<string, size_t> wordCount;
        string word;
        while(cin >> word)
            {
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                if (*(word.end() - 1) == '.' || *(word.end() - 1) == ',')
                {
                    word = word.assign(word.begin(), word.end()-1);
                }
                ++wordCount[word];
            }
            return wordCount;
    }
};

int main()
{
    solution s;
    map<string, size_t> wordCount = s.countWord();
    for (const auto &w:wordCount)
        cout << w.first << " " << w.second << endl;
    return 0;
}