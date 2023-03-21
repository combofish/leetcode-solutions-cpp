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
private:

    // function start.
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp.front() = 0;
        for (auto coin: coins)
            for (int j = coin; j <= amount; j++)
                if (dp[j - coin] != INT_MAX)
                    dp[j] = std::min(dp[j], dp[j - coin] + 1);


        return dp.back() == INT_MAX ? -1 : dp.back();
    }

    /**
     * 先遍历背包，再遍历物品
     * @param coins
     * @param amount
     * @return
     */
    int coinChange_2(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp.front() = 0;
        for (int i = 0; i <= amount; i++)
            for (auto coin: coins)
                if (i - coin >= 0 && dp[i - coin] != INT_MAX)
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);

        return dp.back() == INT_MAX ? -1 : dp.back();
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int rel = 3;
    IC(coins, amount, rel);
    IC(solution->coinChange(coins, amount) == rel);
    IC(solution->coinChange_2(coins, amount) == rel);

    // code end

    delete solution;
    return 0;
}


