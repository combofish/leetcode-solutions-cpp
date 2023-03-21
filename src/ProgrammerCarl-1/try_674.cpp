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
    int findLengthOfLCIS(vector<int> &nums) {
        std::pair<int, int> dp;
        dp.first = nums.front();
        dp.second = 1;
        int result = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > dp.first) {
                dp.first = nums[i];
                dp.second++;
            } else {
                dp.first = nums[i];
                dp.second = 1;
            }

            IC(dp.first, nums[i], dp.second);
            result = std::max(dp.second, result);

        }

        return result;
    }


    int findLengthOfLCIS_2(vector<int> &nums) {
        int result = 1;
        vector<int> dp(nums.size(), 1);

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1])
                dp[i + 1] = dp[i] + 1;

            if (dp[i + 1] > result) result = dp[i + 1];
        }

        return result;

    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {1, 3, 5, 4, 7};
    int rel = 3;
    IC(nums, rel);
    IC(solution->findLengthOfLCIS(nums) == rel);
    IC(solution->findLengthOfLCIS_2(nums) == rel);


    vector<int> nums_2 = {1, 3, 5, 4, 2, 3, 4, 5};
    int rel_2 = 4;
    IC(nums_2, rel_2);
    IC(solution->findLengthOfLCIS(nums_2) == rel_2);
    IC(solution->findLengthOfLCIS_2(nums_2) == rel_2);
    // code end

    delete solution;
    return 0;
}


