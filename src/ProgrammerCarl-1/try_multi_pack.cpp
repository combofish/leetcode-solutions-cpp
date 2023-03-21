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
private:


public:

    void test_multi_pack(vector<int> &weight,
                         vector<int> &value,
                         vector<int> &nums,
                         int bagWeight) {
        IC();
        IC(weight, value, nums, bagWeight);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 1) {
                weight.push_back(weight[i]);
                value.push_back(value[i]);
                nums[i]--;
            }
        }

        IC(weight, value, nums, bagWeight);
        vector<int> dp(bagWeight + 1, 0);
        for (int i = 0; i < weight.size(); i++) {
            //for (int j = weight[i]; j <= bagWeight; j++)
            for (int j = bagWeight; j >= weight[i]; j--)
                dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);

            IC(dp);
            for (int j = 0; j <= bagWeight; j++) {
                cout << dp[j] << " ";
            }
            cout << endl;
        }
        IC(dp);
    }

    void test_multi_pack_2(const vector<int> &weight,
                           const vector<int> &value,
                           const vector<int> &nums,
                           int bagWeight) {
        IC();
        IC(weight, value, nums, bagWeight);
        vector<int> dp(bagWeight + 1, 0);

        for (int i = 0; i < weight.size(); i++) {
            for (int j = bagWeight; j >= weight[i]; j--)
                for (int k = 1; k <= nums[i] && (j - k * weight[i]) >= 0; k++)
                    dp[j] = std::max(dp[j], dp[j - k * weight[i]] + k * value[i]);

            IC(dp);
        }

        IC(dp);

    }




    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> weights = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    vector<int> nums = {2, 3, 2};

    int bagWeight = 10;

    solution->test_multi_pack_2(weights, value, nums, bagWeight);

    solution->test_multi_pack(weights, value, nums, bagWeight);

    // code end

    delete solution;
    return 0;
}


