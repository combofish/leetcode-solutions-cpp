/**
-- question: 零钱兑换
-- method:
 - [*] 动态规划
 - [-] 记忆化搜索

--result:

-- analyse:
Time: O( Sn )
Space: O( S )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    int coinChange(vector<int> &coins, int amount) {
// int n = coins.size();

        vector<int> dp(amount + 1, INT_MAX);
        dp.front() = 0;

        for (auto &coin: coins) {
            for (int j = coin; j <= amount; j++) {
                if (dp[j - coin] != INT_MAX)
                    dp[j] = std::min(dp[j], dp[j - coin] + 1);
            }
        }

        IC(dp);
        return dp.back() == INT_MAX ? -1 : dp.back();

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int ans = 3;

    IC(coins, amount, ans);

    IC(solution->coinChange(coins, amount));


    // code end

    return 0;
}


