#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    void elimDups(vector<string> &words);
    vector<string> vec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    auto &words = vec;
    elimDups(words);
    for(auto &i : words)
        cout<<i<<" ";
    return 0;
}

void elimDups(vector<string> &words)
{
    sort(words.begin(),words.end());
    auto end_uni = unique(words.begin(),words.end());
    words.erase(end_uni, words.end());
}