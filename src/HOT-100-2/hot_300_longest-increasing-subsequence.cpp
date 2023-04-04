/**
-- question: 最长递增子序列
-- method:
 - [-] 动态规划
 - [ ] 贪心 + 二分查找

--result:

-- analyse:
Time: O(n^2)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int lengthOfLIS(vector<int> &nums) {

        int n = nums.size();
        vector<int> dp(n + 1, 1);
        IC(n, dp);

//        dp.front() = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = n; j > i; j--) {

                // for (int j = i + 1; j <= n; j++) {
                if (nums[i - 1] < nums[j - 1]) {
                    dp[j] = std::max(dp[j], dp[i] + 1);
//                    IC(dp);
                }
            }
            IC(dp);
        }

        // return dp.back();
        return *std::max_element(dp.cbegin(), dp.cend());

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start


    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int ans = 4;

    vector<int> ans_s = {2, 3, 7, 101};

    IC(nums, ans, ans_s);

    IC(solution->lengthOfLIS(nums));

    // code end

    return 0;
}
