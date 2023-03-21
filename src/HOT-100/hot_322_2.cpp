/**
-- question: 零钱兑换
-- method:
 - [ ] 记忆化搜索
 - [ ] 动态规划
 - [*] 动态规划

--result:

-- analyse:
Time: O(Sn)
Space: O(S)
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <climits>

class Solution {

    // function start.
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp.front() = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j - coins[i]] != INT_MAX) dp[j] = std::min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        if (dp.back() == INT_MAX) return -1;
        return dp.back();
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> coins = {1, 2, 5};
    int amount = 11, rel = 3;

    IC(coins, amount, rel);

    IC(solution->coinChange(coins, amount));

    // code end

    return 0;
}
