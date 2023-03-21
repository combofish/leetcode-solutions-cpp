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

        auto robRange = [&nums](int start, int end) -> int {
            if (start == end) return nums[start];
            vector<int> dp(nums.size());
            dp[start] = nums[start];
            dp[start + 1] = std::max(nums[start], nums[start + 1]);
            for (int i = start + 2; i <= end; i++)
                dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
            return dp[end];
        };

        int result_1 = robRange(0, nums.size() - 2);
        int result_2 = robRange(1, nums.size() - 1);
        return std::max(result_1, result_2);

    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {2, 3, 2};
    int rel = 3;
    IC(nums, rel);

    IC(solution->rob(nums) == rel);
    // code end

    delete solution;
    return 0;
}


