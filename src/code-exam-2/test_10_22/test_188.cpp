

#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;
class Solution {
public:
    int maxProfit2(int k, vector<int> &prices) {

        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        for (int j = 1; j < 2 * k; j += 2) {
            dp[0][j] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 0; j < 2 * k - 1; j += 2) {
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }
        IC(dp);

        return dp[prices.size() - 1][2 * k];
    }
    int maxProfit(int k, vector<int> &prices) {
        if (prices.size() == 0) return 0;

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(k * 2 + 1, 0));

        for (int i = 1; i <= 2*k; i += 2) {
            dp[0][i] = -prices.front();
        }

        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i - 1][0];

            for (int j = 1; j <= k * 2; j += 2) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                dp[i][j + 1] = std::max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
            }
        }

        IC(dp);

        return dp.back().back();
    }
};
int main(int argc, char const *argv[]) {

    Solution sol;

    int k = 2;
    vector<int> nums = {2, 4, 1};
    IC(k, nums);

    IC(sol.maxProfit(k, nums));
    IC(sol.maxProfit2(k, nums));

    return 0;
}
