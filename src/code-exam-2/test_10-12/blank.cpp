#include <icecream.hpp>
#include <iostream>

using namespace std;

int gcd(int a, int b) {

    return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, char const *argv[]) {

    int n = 3, m = 4;
    int ans = 6;

    IC(n, m, ans);


    ans = m + n - gcd(m, n);

    IC(ans);
    return 0;
}
