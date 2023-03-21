/**
-- question: 买卖股票的最佳时机
-- method:
 - [*] 动态规划

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();

        // 持有， 不持有

        auto dp = vector<vector<int>>(n, vector<int>(2));
        dp.front().front() = -prices.front();

        for (int i = 1; i < n; i++) {
            dp[i][0] = std::max(dp[i - 1][0], -prices[i]);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }

        return dp.back().back();
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int rel = 5;
    IC(prices, rel);
    IC(solution->maxProfit(prices));

    // code end

    return 0;
}
