#include <icecream.hpp>
#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    int T, H;

    n = 3;
    T = 5;
    H = 4;

    vector<int> ts, hs, as;

    ts = {1, 2, 4};
    hs = {2, 1, 1};
    as = {2, 3, 5};


    vector<vector<int>> dp(T + 1, vector<int>(H + 1, 0));

    // dp.front().front() = 0;

    for (int k = 0; k < n; ++k) {

        for (int i = T; i >= ts[k]; --i) {
            for (int j = H; j >= hs[k]; --j) {
                dp[i][j] = std::max(dp[i][j], dp[i - ts[k]][j - hs[k]] + as[k]);
            }
        }

        IC(dp);
    }

    cout << dp.back().back() << endl;


    return 0;
}