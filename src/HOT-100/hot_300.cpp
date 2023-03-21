/**
-- question: 最长递增子序列
-- method:
 - [*] 动态规划
 - [ ] 贪心 + 二分查找 --- best ---

--result:

-- analyse:
Time: O( n^2 )
Space: O( n )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.size() <= 1) return nums.size();

        int result = 0;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i]) dp[i] = std::max(dp[i], dp[j] + 1);

            if (dp[i] > result) result = dp[i];
        }
        return dp.back();
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int rel = 4;
    IC(nums, rel);
    IC(solution->lengthOfLIS(nums) == rel);

    // code end

    return 0;
}


