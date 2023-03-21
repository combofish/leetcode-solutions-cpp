/**
-- question: 零钱兑换
-- method:
 - [ ] 记忆化搜索
 - [*] 动态规划

--result:

-- analyse:
Time: O(Sn)
Space: O(S)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp.front() = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i && dp[i - coins[j]] != amount + 1)
                    dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp.back() > amount ? -1 : dp.back();
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
