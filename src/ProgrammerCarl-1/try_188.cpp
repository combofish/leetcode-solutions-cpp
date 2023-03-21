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
    int maxProfit(int k, vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(k * 2 + 1, 0));
        for (int j = 1; j < k * 2; j += 2)
            dp[0][j] = -prices[0];

        for (int i = 1; i < prices.size(); i++)
            for (int j = 0; j < 2 * k - 1; j += 2) {
                dp[i][j + 1] = std::max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                dp[i][j + 2] = std::max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }

        return dp.back().back();
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    int k = 2;
    vector<int> prices = {2, 4, 1};
    int rel = 2;
    IC(k, prices, rel);
    IC(solution->maxProfit(k, prices) == rel);

    // code end

    delete solution;
    return 0;
}


