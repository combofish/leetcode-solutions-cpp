
#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int> &coins) {

        vector<int> dp(amount + 1, 0);
        dp.front() = 1;

        for (auto &coin: coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }

        IC(dp);


        dp.clear();
        dp.resize(amount + 1);
        dp.front() = 1;
        for(int i = 0; i<= amount; ++i){
            for(auto &coin: coins){
                if(i >= coin) dp[i] += dp[i- coin];
            }
        }

        IC(dp);

        return dp.back();
    }
};

int main(int argc, char const *argv[]) {

    Solution sol;
    int amount = 4;
    vector<int> coins = {1, 2, 3};

    IC(amount);


    auto res = sol.change(amount, coins);
    IC(res);


    /* code */
    return 0;
}
