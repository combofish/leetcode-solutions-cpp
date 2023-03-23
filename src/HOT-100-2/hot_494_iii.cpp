/**
-- question: 目标和
-- method:
 - [ ] 回溯
 - [*] 动态规划

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
    int findTargetSumWays(vector<int> &nums, int target) {
        auto sum = std::accumulate(nums.cbegin(), nums.cend(), 0);

        auto diff = sum - target;
        if (diff < 0 || diff % 2) return 0;
        auto neg = diff / 2;

        IC(neg);

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(neg + 1));
        dp.front().front() = 1;
        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1];
            for (int j = 0; j <= neg; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= num) {
                    dp[i][j] += dp[i - 1][j - num];
                }
            }
        }


        IC(dp);
        return dp.back().back();
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    //    vector<int> nums = {1, 1, 1, 1, 1};
    //    int target = 3;
    //    int ans = 5;
    //    IC(nums, target, ans);

    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    int target = 4;
    int ans = 28;
    IC(nums, target, ans);

    IC(solution->findTargetSumWays(nums, target));

    // code end

    return 0;
}


