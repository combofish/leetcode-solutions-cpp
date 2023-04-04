/**
-- question: 最长递增子序列
-- method:
 - [ ] 动态规划
 - [*] 贪心 + 二分查找

--result:

-- analyse:
Time: O( nlog(n) )
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int lengthOfLIS(vector<int> &nums) {
        int len = 1;
        int n = nums.size();

        vector<int> dp(n + 1, 0);
        dp[len] = nums.front();

        for (int i = 1; i < n; i++) {
            if (nums[i] > dp[len]) dp[++len] = nums[i];
            else {
                int l = 1, r = len, pos = 0;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (dp[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                dp[pos + 1] = nums[i];
            }

            IC(dp);

        }
        return len;

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start


    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18, 1};
    // vector<int> nums = {10, 9, 101, 18};
    int ans = 4;

    vector<int> ans_s = {2, 3, 7, 101};

    IC(nums, ans, ans_s);

    IC(solution->lengthOfLIS(nums));

    // code end

    return 0;
}
