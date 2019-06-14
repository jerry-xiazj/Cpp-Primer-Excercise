#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> vec;
    cout<<"vec.size = "<<vec.size();
    cout<<" capacity = "<<vec.capacity()<<endl;

    for (vector<int>::size_type ix = 0; ix != 24; ++ix)
        vec.push_back(ix);
    cout<<"vec.size = "<<vec.size();
    cout<<" capacity = "<<vec.capacity()<<endl;

    vec.insert(vec.end(),42);
    cout<<"vec.size = "<<vec.size();
    cout<<" capacity = "<<vec.capacity()<<endl;
    return 0;
}