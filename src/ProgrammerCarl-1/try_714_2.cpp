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
    int maxProfit(vector<int> &prices, int fee) {
        if (prices.size() <= 1) return 0;

        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp.front().front() = -prices.front();

        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }

        return std::max(dp.back().front(), dp.back().back());
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    int rel = 8;
    IC(prices, fee, rel);
    IC(solution->maxProfit(prices, fee) == rel);

    // code end

    delete solution;
    return 0;
}


