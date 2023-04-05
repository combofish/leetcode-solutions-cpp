/**
-- question: 最佳买卖股票时机含冷冻期
-- method:
 - [-] 动态规划

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "../combofish_utils.hpp"

class Solution {

    // function start.
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();


        // dp[i][0]. 买入状态
        // dp[i][1]. 卖出状态
        // dp[i][2]. 今天卖出
        // dp[i][3]. 冷冻状态

        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp.front().front() = -prices.front();

        for (int i = 1; i < n; i++) {
            dp[i][0] = std::max(dp[i - 1][0], std::max(dp[i - 1][3], dp[i - 1][1]) - prices[i]);
            dp[i][1] = std::max(dp[i - 1][3], dp[i - 1][1]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }

        IC(dp);
        return std::max({dp.back()[1], dp.back()[2], dp.back()[3]});


    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> prices = {1, 2, 3, 0, 2};
    int ans = 3;

    IC(prices, ans);
    IC(solution->maxProfit(prices));

    // code end

    return 0;
}
