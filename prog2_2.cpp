#include <iostream>
// i在prog2_1.cpp中定义，在function和main中声明
// i的作用域为整个prog2_2.cpp文件
int function()
{
    extern int i;
    std::cout << "i in function is " << i << std::endl;
    i++;
    std::cout << "i in function is " << i << std::endl;
    return 0;
}

int main()
{
    extern int i;
    std::cout << "i in main is " << i << std::endl;
    i = 100;
    std::cout << "i in main is " << i << std::endl;
    function();
    std::cout << "i in main is " << i << std::endl;
    return 0;
}