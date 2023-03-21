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
        auto mod2 = [](int i) { return i % 2; };
        vector<vector<int>> dp(2, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        IC(dp[0]);

        for (int i = 1; i < prices.size(); i++) {
            dp[mod2(i)][0] = std::max(dp[mod2(i - 1)][0], dp[mod2(i - 1)][1] - prices[i]);
            dp[mod2(i)][1] = std::max(dp[mod2(i - 1)][1], dp[mod2(i - 1)][0] + prices[i]);

            IC(dp[mod2(i)]);
        }

        return dp[mod2(prices.size() - 1)].back();
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int rel = 7;
    IC(prices, rel);

    IC(solution->maxProfit(prices) == rel);
    // code end

    delete solution;
    return 0;
}


