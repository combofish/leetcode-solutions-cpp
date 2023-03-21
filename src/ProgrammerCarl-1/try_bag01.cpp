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
    void test_2_wei_bag_problem(vector<int> &weight, vector<int> &value, int bag_weight) {
        vector<vector<int>> dp(weight.size(), vector<int>(bag_weight + 1, 0));
        for (int j = weight[0]; j <= bag_weight; j++)
            dp[0][j] = value[0];

        IC(dp);

        for (int i = 1; i < weight.size(); i++)
            for (int j = 0; j <= bag_weight; j++)
                if (j < weight[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);

        IC(dp);
    }

    void test_1_wei_bag_problem(vector<int> &weight, vector<int> &value, int bag_weight) {
        vector<int> dp(bag_weight + 1, 0);
        IC(dp);

        for (int i = 0; i < weight.size(); i++) {
            for (int j = bag_weight; j >= weight[i]; j--) {
                dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
                IC(dp);
            }
            IC(i, dp);
        }


        IC(dp);

    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    IC(weight, value, bagWeight);

    solution->test_2_wei_bag_problem(weight, value, bagWeight);
    solution->test_1_wei_bag_problem(weight, value, bagWeight);

    // code end

    delete solution;
    return 0;
}


