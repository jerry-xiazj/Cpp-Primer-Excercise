#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

int main()
{
    string line = "first, middle, last";
    auto comma = find(line.rbegin(),line.rend(),',');
    cout<<string(comma.base(),line.end())<<endl;
    return 0;
}