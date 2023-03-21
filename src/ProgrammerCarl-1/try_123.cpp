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
         * 0, no operator
         * 1, 1th buy
         * 2, 1th sold
         * 3, 2th buy
         * 4, 2th sold
         */

        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = std::max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = std::max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }

        return dp.back().back();

    }

    int maxProfit_2(vector<int> &prices){
        vector<int> dp(5,0);
        dp[1] = -prices[0];
        dp[3] = -prices[0];

        for(int i = 1; i< prices.size(); i++){
            dp[1] = std::max(dp[1], dp[0] - prices[i]);
            dp[2] = std::max(dp[2], dp[1] + prices[i]);
            dp[3] = std::max(dp[3], dp[2] - prices[i]);
            dp[4] = std::max(dp[4], dp[3] + prices[i]);
        }

        return dp.back();
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int rel = 6;
    IC(prices, rel);
    IC(solution->maxProfit(prices));
    IC(solution->maxProfit_2(prices));

    // code end

    delete solution;
    return 0;
}


