#include <iostream>
int main()
{
    int i = 100;
    int *j = &i;    //j是指针，存储i的地址
    int &k = *j;    //k是j所指对象的别名
    std::cout << *j << std::endl;
    std::cout << k << std::endl;
    i++;
    std::cout << *j << std::endl;
    std::cout << k << std::endl;
    return 0;
}