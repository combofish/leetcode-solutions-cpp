/**
-- question: 连续子数组的最大和
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp.front() = nums.front();

        int result = dp.front();
        for (int i = 1; i < n; i++) {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > result) result = dp[i];
        }

        IC(dp);
        return result;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int rel = 6;

    IC(nums, rel);
    IC(solution->maxSubArray(nums) == rel);
    // code end

    return 0;
}
