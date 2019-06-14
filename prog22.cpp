#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    map<string, size_t> word_count{{"c",3},{"b",2},{"a",1}};
    word_count.insert({"d",4});
    cout << word_count.emplace("c",6).second << endl;
    for(auto &ix : word_count)
    cout << ix.first << ix.second << endl;
    cout <<word_count.emplace("d",6).first->second<<endl;

    return 0;
}