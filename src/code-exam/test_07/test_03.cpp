//
// Created by larry on 23-3-29.
//

#include <iostream>
#include <limits.h>

#include <icecream.hpp>

using namespace std;

long long fab(long long n) {
    long long ans = n;
    while (--n)
        ans *= n;

    return ans;
}

int main() {

    long long n;

    // cin>>n;

    n = 25;

//    int x, y;
//    x = 1;
//    y = 1;

//    IC(fab(1), fab(2), fab(5));

    pair<int, int> ans = {1, 1};
    long long min_val = n;

    int x = 3;
    while (1) {
        auto fb = fab(x);
        IC(fb);
        if (fb - 1 > n) break;

        long long y = n / (fb - 1);

        auto tmp = std::abs((fb - 1) * y - n);
        if (tmp < min_val) {
            min_val = tmp;
            ans.first = x;
            ans.second = (int) y;
        }

        x++;

    }

    cout << ans.first << " " << ans.second << endl;
    return 0;
}