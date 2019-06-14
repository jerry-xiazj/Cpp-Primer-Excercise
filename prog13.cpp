#include <iostream>
#include <initializer_list>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::initializer_list;
using std::cin;
using std::cout;
using std::endl;

constexpr int new_size(){return 42;}
constexpr size_t scale(size_t cnt){return new_size()*cnt;}

int main()
{
    int arr[scale(2)];
    int i = 2;
    int a2[scale(i)];
    return 0;
}