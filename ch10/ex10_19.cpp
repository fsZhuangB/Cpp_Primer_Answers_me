#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;

void elimDups(vector<string>& words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}
void biggies(vector<string>& words, int sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string& a, const string& b){ return a.size() < b.size(); });
    auto wc = stable_partition(words.begin(), words.end(), [sz](const string& a){ return a.size() < sz;});
    auto count = words.end() - wc;
    cout << "The count is " << count << endl;
    for_each(wc, words.end(), [](const string& s){ cout << s << " ";});
}
int main()
{
    string a;
    vector<string> v={"hi", "red", "hi", "test", "goooood" ,"uuu", "red" ,"goooood" };

    biggies(v, 3);
}