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
private:

    // function start.
public:

    /**
     * err: 求组合
     * @param nums
     * @param target
     * @return
     */
    int combinationSum4(vector<int> &nums, int target) {
        vector<int> dp(target + 1, 0);
        dp.front() = 1;
        for (auto num: nums)
            for (int j = num; j <= target; j++)
                dp[j] += dp[j - num];

        IC(dp);
        return dp.back();
    }

    /**
     * 求排列
     * @param nums
     * @param target
     * @return
     */
    int combinationSum4_2(vector<int> &nums, int target) {
        vector<int> dp(target + 1, 0);
        dp.front() = 1;
        for (int i = 0; i <= target; i++)
            for (int num: nums)
                if (i - num >= 0 && dp[i] < INT_MAX - dp[i - num])
                    dp[i] += dp[i - num];

        return dp.back();
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {1, 2, 3};
    int target = 4;
    int rel = 7;

    IC(nums, target, rel);
    IC(solution->combinationSum4(nums, target) == rel);
    IC(solution->combinationSum4_2(nums, target) == rel);

    // code end

    delete solution;
    return 0;
}


