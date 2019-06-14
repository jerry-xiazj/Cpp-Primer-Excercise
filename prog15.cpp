#include <list>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
int main()
{
    list<string> names;
    vector<const char*> oldstyle = {"Jack","Jerry","John","Mary"};
    list<string> names2;

    for (auto i = oldstyle.cbegin() ; i != oldstyle.cend() ; ++i)
    {
        cout<<*i<<endl;
    }
    cout<<"***********"<<endl;

    names.assign(oldstyle.cbegin() , oldstyle.cend());
    for (auto &i : names)
    {
        cout<<i<<endl;
    }
    cout<<"***********"<<endl;

    int n = 1;
    names2 = names;
    auto itr = names2.begin();
    names2.assign(itr , names2.end());
    names2.insert(++names2.begin(),1,"Mike");
    for(auto &i : names2)
    {
        cout<<i<<endl;
    }
    return 0;
}