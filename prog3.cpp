#include <iostream>
int main()
{
    int a = 42;
    const int &r = a;
    std::cout << "r = " << r << std::endl;
    a++;
    std::cout << "a = " << a << std::endl;
    std::cout << "r = " << r << std::endl;
    return 0;
}