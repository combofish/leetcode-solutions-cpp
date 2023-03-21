/**
-- question: 最长递增子序列
-- method:
 - [ ] 动态规划
 - [*] 贪心 + 二分查找 --- best ---

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
    /**
     * 数组 dp[i] ，表示长度为 i 的最长上升子序列的末尾元素的最小值，
     * 用 len 记录目前最长上升子序列的长度
     * @param nums
     * @return
     */
    int lengthOfLIS(vector<int> &nums) {
        int len = 1, n = nums.size();
        if (n <= 1) return n;

        vector<int> dp(n + 1, 0);
        dp[len] = nums.front();
        for (int i = 1; i < n; i++) {
            if (nums[i] > dp[len]) {
                dp[++len] = nums[i];
            } else {
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

            IC(i, len, dp);
        }


        return len;
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


