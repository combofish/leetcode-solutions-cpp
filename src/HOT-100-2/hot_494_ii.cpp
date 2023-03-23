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

        // if (std::abs(target) > sum) return 0;

        auto diff = sum - target;
        if (diff < 0 || diff % 2) return 0;
        auto neg = diff / 2;

        IC(neg);

        vector<int> dp(neg + 1, 0);
        dp.front() = 1;

        for (auto &n: nums) {
            for (int j = neg; j >= n; j--)
                dp[j] += dp[j - n];

            IC(dp);
        }

        return dp.back();
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    int target = 4;
    int ans = 28;
    IC(nums, target, ans);

    IC(solution->findTargetSumWays(nums, target));

    // code end

    return 0;
}


