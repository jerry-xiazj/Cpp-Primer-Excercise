#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;
int main()
{
    int ia[] = {1,2,3,4,5,6,7,8};
    decltype (ia) ia2 = {1,2,3,4,5,6,7};
    int *beg = begin(ia);
    int *last = end(ia);
    cout << ia[7] << endl;
    cout << *beg << endl;
    cout << *last << endl;
    cout << ia2[7] << endl;
    //    decltype (ia) ia2 = {1,2,3,4,5,6,7,8,9};会发生错误
    return 0;
}