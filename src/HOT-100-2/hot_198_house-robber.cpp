/**
-- question: 打家劫舍
-- method:
 - [-] 动态规划

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return nums.front();

        vector<int> dp(n, 0);
        dp.front() = nums.front();
        dp[1] = std::max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        IC(dp);

        return dp.back();
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> nums = {2, 7, 9, 3, 1};
    int ans = 12;

    IC(nums, ans);
    IC(solution->rob(nums));


    // code end

    return 0;
}
