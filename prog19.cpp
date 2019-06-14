#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    void biggies(vector<string> &words, vector<string>::size_type sz);

    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    for(const auto &i : words)
        cout<<i<<" ";
    cout<<endl;
    biggies(words, 4);
    return 0;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    //将words中的单词按照字典顺序排序，删除重复的单词
    sort(words.begin(), words.end());
    auto end_uni = unique(words.begin(),words.end());
    words.erase(end_uni, words.end());
    //将words中的单词按照长短排序，相同长短按照字典顺序排序
    stable_sort(words.begin(), words.end(), 
                [](const string &s1, const string &s2)
                { return s1.size() < s2.size(); });
    //找到大于等于指定长度sz的单词的位置
    auto wc = find_if(words.begin(), words.end(),
                [sz](const string &a)
                { return a.size() >= sz; });
    //计数并输出个数
    auto count = words.end() - wc;
    auto make_plural = [](vector<string>::size_type ctr, 
                const string &word, const string &ending)
                ->string
                { return (ctr > 1) ? word + ending : word; };
    cout << count << " " << make_plural(count, "word", "s")
    << " of length " << sz << " or more." << endl;
    //输出这些单词
    for_each(wc, words.end(),
                [](const string &s)
                { cout << s << " "; });
    cout << endl;
}