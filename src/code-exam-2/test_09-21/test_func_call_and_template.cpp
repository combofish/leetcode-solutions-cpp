#include <icecream.hpp>
#include <iostream>
using namespace std;

template<typename T>
T func(T a) {
    return ++a;
}

int func(int a) {
    return --a;
}

int main() {

    int a = 10;
    IC(func(a)); // 9

    a = 10;
    IC(func<int>(a)); // 10

    return 0;
}