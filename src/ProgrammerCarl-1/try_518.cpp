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
    int change(int amount, vector<int> &coins) {
        vector<int> dp(amount + 1, 0);
        dp.front() = 1;

        for (int i = 0; i < coins.size(); i++)
            for (int j = coins[i]; j <= amount; j++)
                dp[j] += dp[j - coins[i]];

        return dp.back();
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    int rel = 4;

    IC(amount, coins, rel);
    IC(solution->change(amount, coins) == rel);
    // code end

    delete solution;
    return 0;
}


