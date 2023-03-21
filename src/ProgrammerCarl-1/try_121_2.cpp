/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
private:


public:

    int maxProfit(vector<int> &prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = std::max(dp[i - 1][0], -prices[i]);
            dp[i][1] = std::max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }

        return dp.back().back();

    }

    int maxProfit_2(vector<int> &prices) {
        vector<vector<int>> dp(2, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[i % 2][0] = std::max(dp[(i - 1) % 2][0], -prices[i]);
            dp[i % 2][1] = std::max(dp[(i - 1) % 2][1], prices[i] + dp[(i - 1) % 2][0]);
        }

        return dp[(prices.size() -1)% 2].back();
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int rel = 5;
    IC(prices, rel);
    IC(solution->maxProfit(prices) == rel);
    IC(solution->maxProfit_2(prices) == rel);

    // code end

    delete solution;
    return 0;
}


