// 练习5.14
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main()
{
    vector<string> s;
    string w, maxWord;
    int maxCnt = 0, tempCnt = 1;
    while(cin >> w) 
        s.push_back(w);
    auto beg = s.begin();
    while(beg != s.end())
    {
        if(*(beg+1)==*beg) ++tempCnt;
        else if(tempCnt > maxCnt)
        {
            maxCnt = tempCnt;
            tempCnt = 1;
            maxWord = *beg;
        }
        ++beg;
    }
    cout << maxWord << " appears " << maxCnt << " times " << endl;
    return 0;
}