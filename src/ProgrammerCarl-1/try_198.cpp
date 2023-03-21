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
    int rob(vector<int> &nums) {
        if (nums.size() == 1) return nums.back();
        if (nums.size() == 2) return std::max(nums.front(), nums.back());

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++)
            dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);

        return dp.back();

    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {2, 7, 9, 3, 1};
    int rel = 12;

    IC(nums, rel);
    IC(solution->rob(nums) == rel);

    // code end

    delete solution;
    return 0;
}


