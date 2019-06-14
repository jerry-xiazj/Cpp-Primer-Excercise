#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int grade;
    cin >> grade;
    string finalgrade = (grade>90)?"high pass"
        :(grade<60)?"fail":"pass";
    cout << finalgrade << endl;
    return 0;
}