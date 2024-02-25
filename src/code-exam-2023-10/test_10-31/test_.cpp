#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

struct produt {
    int len, hei;

// public:
//     produt(int a, int b) : len(a), hei(b){}
};


int main(int argc, char const *argv[]) {

    produt arr[3] = {{8, 4}, {10, 5}, {12, 6}};
    produt *p = arr;

    IC((*++p).len);
    return 0;
}
