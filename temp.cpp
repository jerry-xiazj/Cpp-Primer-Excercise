class A
{
public:
    virtual int fcn() {return 1;}
};

class B : public A
{
public:
    int fcn(int) {return 2;}
};

class C : public B
{
public:
    //int fcn(int) {return 3;}
    int fcn() override {return 4;}
};

#include <iostream>
using namespace std;

int main()
{
    A objA;
    B objB;
    C objC;
    cout << "objA.fcn() = " << objA.fcn() << endl;
    //cout << "objB.fcn() = " << objB.fcn() << endl;
    cout << "objB.fcn(1) = " << objB.fcn(1) << endl;
    cout << "objC.fcn() = " << objC.fcn() << endl;
    cout << "objC.fcn(1) = " << objC.fcn(1) << endl;
    return 0;
}