// 练习5.14
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    const int &r = 42;
    int r2 = r;
//  int &r3 = r; 编译报错
    return 0;
}