#include <iostream>

using namespace std;

class M {
public:
    M() { cout << __FUNCTION__ << endl; }
};

class N {
public:
    N() { cout << __FUNCTION__ << endl; }
};

class A {
public:
    A() { cout << __FUNCTION__ << endl; }
};

class B : public A {
public:
    B() { cout << __FUNCTION__ << endl; }

private:
    M m1;
    M m2;

    static N n;
};

N B::n;

int main(void) {
    B b1;

    cout << endl
         << endl
         << "=============================" << endl
         << endl;

    cout << "b2：" << endl;
    B b2;




    return 0;
}
