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
public:
    int maxProfit(vector<int> &prices) {

        /**
         * 0, hold
         * 1, buy
         * 2, sold
         * 3, freeze
         */

        if (prices.size() <= 1) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp.front().front() = -prices.front();

        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = std::max(dp[i - 1][0], std::max(dp[i - 1][3], dp[i - 1][1]) - prices[i]);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }

        return std::max(dp.back()[1],
                        std::max(dp.back()[2], dp.back()[3]));
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> prices = {1, 2, 3, 0, 2};
    int rel = 3;
    IC(prices, rel);
    IC(solution->maxProfit(prices) == rel);

    // code end

    delete solution;
    return 0;
}


