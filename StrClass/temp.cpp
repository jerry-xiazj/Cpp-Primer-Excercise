#include "StrBlobPtr.h"
#include "StrBlob.h"
#include <string>

using namespace std;

int main()
{
    StrBlob s1 {"apple", "book"};
    StrBlobPtr ws1(s1);
    const string s2 = s1.front();
    return 0;
}