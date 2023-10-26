

#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {

        vector<int> dp(amount + 1, amount + 1);
        dp.front() = 1;

        for (auto &coin: coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }

        IC(dp);
        return dp.back() == amount + 1 ? -1 : dp.back();
    }
};
int main(int argc, char const *argv[]) {

    vector<int> coins = {1, 2, 5};
    int amount = 11;
    IC(coins, amount);

    Solution sol;
    auto ans = sol.coinChange(coins, amount);
    IC(ans);
    return 0;
}
