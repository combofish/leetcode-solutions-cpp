
#include <icecream.hpp>

using namespace std;


class A{
    int a;
    void func(){};
};
class B{
    int b;
    virtual void func(){};
};

int main(int argc, char const *argv[]) {
    /* code */

    A a;
    B b;

    IC(sizeof(a), sizeof(b));
 

    return 0;
}
