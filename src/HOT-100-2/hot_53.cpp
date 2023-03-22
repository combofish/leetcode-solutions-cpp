/**
-- question:
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
        int ans = nums.front();

        dp.front() = nums.front();
        for (int i = 1; i < n; i++) {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > ans) ans = dp[i];
        }

        return dp.back();
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = 6;
    IC(nums, ans);


    IC(solution->maxSubArray(nums));
    // code end

    return 0;
}
