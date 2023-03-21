/**
-- question: 乘积最大子数组
-- method:
 - [ ] for, for
 - [ ] 动态规划
 - [*] 动态规划， 优化空间

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
    int maxProduct(vector<int> &nums) {
        int ans = nums.front(), maxF = nums.front(), minF = nums.front();

        for (int i = 1; i< nums.size(); i++) {
            int item = nums[i];
            int mx = maxF,mn = minF;
            maxF = std::max({item, mx * item, mn * item});
            minF = std::min({item, mx * item, mn * item});
            if (maxF > ans) ans = maxF;

            IC(maxF, minF, ans);
        }
        return ans;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> nums = {2, 3, -2, 4};
    int rel = 6;
    IC(nums, rel);

    IC(solution->maxProduct(nums) == rel);

    // code end

    return 0;
}
