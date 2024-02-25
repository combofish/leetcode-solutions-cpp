#include <icecream.hpp>
#include <iostream>

using namespace std;

char fun(char x, char y) {
    if (x) return (y);
}


int main() {


    int a = '0', b = '1', c = '2';

    IC(fun(a,b));
    IC(fun(b, c));

    IC(fun(
            fun(a, b),
            fun(b, c))
            );


    if('0') IC('0');
    if('1') IC('1');

    return 0;
}