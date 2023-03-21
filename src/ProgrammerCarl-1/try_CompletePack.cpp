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
    void test_Complete_Pack(vector<int> &weights, vector<int> &values, int bagWeight) {
        vector<int> dp(bagWeight + 1, 0);
        for (int i = 0; i < weights.size(); i++)
            for (int j = weights[i]; j <= bagWeight; j++)
                dp[j] = std::max(dp[j], dp[j - weights[i]] + values[i]);

        IC(dp);
    }

    /**
     * 先遍历背包再遍历物品
     * @param weights
     * @param values
     * @param bagWeight
     */
    void test_Complete_Pack_2(vector<int> &weights, vector<int> &values, int bagWeight) {
        vector<int> dp(bagWeight + 1, 0);
        for (int j = 0; j <= bagWeight; j++)
            for (int i = 0; i < weights.size(); i++)
                if (j - weights[i] >= 0) dp[j] = std::max(dp[j], dp[j - weights[i]] + values[i]);

        IC(dp);
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start

    vector<int> weights = {1, 3, 4};
    vector<int> values = {15, 20, 30};
    int bagWeight = 4;
    solution->test_Complete_Pack(weights, values, bagWeight);
    solution->test_Complete_Pack_2(weights, values, bagWeight);

    IC();

    // code end

    delete solution;
    return 0;
}


