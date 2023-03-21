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

    int lengthOfLIS(vector<int> &nums) {
        if (nums.size() <= 1) return nums.size();

        vector<int> dp(nums.size(), 1);
        int result = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j]) dp[i] = std::max(dp[i], dp[j] + 1);

            result = std::max(result, dp[i]);
        }

        return result;
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int rel = 4;
    IC(nums, rel);
    IC(solution->lengthOfLIS(nums) == rel);

    IC();
    vector<int> nums_2 = {0, 1, 0, 3, 2, 3};
    int rel_2 = 4;
    IC(nums_2, rel_2);
    IC(solution->lengthOfLIS(nums_2) == rel_2);


    IC();
    vector<int> nums_3 = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    int rel_3 = 6;
    IC(nums_3, rel_3);
    IC(solution->lengthOfLIS(nums_3) == rel_3);

    // code end

    delete solution;
    return 0;
}


