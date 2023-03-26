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
        if (amount < 1) return 0;
        count.resize(amount);

        auto ans = dp(coins, amount);
        IC(count);
        return ans;
    }

private:

    vector<int> count;

    int dp(const vector<int> &coins, int rem) {
        if (rem < 0) return -1;
        if (!rem) return 0;
        if (count[rem - 1]) return count[rem - 1];

        int minNum = INT_MAX;
        for (auto coin: coins) {
            auto res = dp(coins, rem - coin);
            if (res >= 0 && res < minNum) minNum = res + 1;
        }

        count[rem - 1] = minNum == INT_MAX ? -1 : minNum;
        return count[rem - 1];
    }
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


