/**
-- question: 打家劫舍
-- method:
 - [-] 动态规划

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
        if (n == 1) return nums.front();

        int curr = nums.front();
        int next = std::max(curr, nums[1]);

        for (int i = 2; i < n; i++) {
            auto tmp = std::max(curr + nums[i], next);

            curr = next;
            next = tmp;
        }
        return next;

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
