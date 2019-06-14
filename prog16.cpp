#include <array>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    array<int,3> a = {1,2,3};
    array<int,3> b = {4,5,6};
    int *ptr = &a[2];
    cout<<*ptr<<endl;
    swap(a,b);
    cout<<*ptr<<endl;
    cout<<"***********"<<endl;
    
    vector<int> c = {1,2,3};
    vector<int> d = {4,5,6};
    int *ptr2 = &c[2];
    cout<<*ptr2<<endl;
    swap(c,d);
    cout<<*ptr2<<endl;
    cout<<"***********"<<endl;
    for(auto &i : c)
    {
        cout<<i<<endl;
    }
    return 0;
}

