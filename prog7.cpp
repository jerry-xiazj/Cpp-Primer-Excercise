//#include <iostream>
//iostream 里包含了begin,end,size_t
#include <cstddef>
#include <iterator>
//using std::cin;
//using std::cout;
//using std::endl;
using std::begin;
using std::end;
int main()
{
    constexpr size_t sz = 5;
    int arr[sz] = {1,2,3,4,5};
    int *p = arr + sz;
//    cout << *p << endl;
    return 0;
}