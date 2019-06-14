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

char &get_val(string &str, string::size_type ix)
{
    return str[ix];
}

int main()
{
    string s("a value");
    cout << s << endl;
    get_val(s,0) = 'A';
    cout << get_val(s,0) << endl;
    return 0;
}