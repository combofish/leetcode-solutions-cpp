#include <bits/stdc++.h>
#include <icecream.hpp>
using namespace std;

class Solution {
    inline bool isPrime(int n) {
        for (int i = 1; i <= sqrt(n); ++i) {
            if (i * i == n) return false;
        }

        return true;
    }

public:
    int countPrimes(int n) {
        if (n <= 1) return 0;

        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime(i)) {
                IC(i);
                ++ans;
            }
        }

        return ans;
    }
};
int main(int argc, char const *argv[]) {

    int n = 10;
    IC(n);

    Solution sol;
    IC(sol.countPrimes(n));
    return 0;
}