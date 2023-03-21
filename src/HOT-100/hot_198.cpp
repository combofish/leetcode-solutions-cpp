/**
-- question: 打家劫舍
-- method:
 - [*] 动态规划

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
	if(n<2) return nums.front();

        auto dp = vector<int>(n, 0);
        dp[0] = nums.front();
        dp[1] = std::max(dp[0], dp[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
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
    vector<int> nums = {1, 2, 3, 1};
    int rel = 4;

    IC(solution->rob(nums) == rel);
    // code end

    return 0;
}
