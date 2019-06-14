#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

int main()
{
    string st = "Hello";
    ostream &print (ostream &os, const string &s, char c);
    auto pp = bind(print, ref(cout), st, _1);
    pp('2');
    return 0;
}

ostream &print (ostream &os, const string &s, char c)
{
    return os << s << c;
}