/**
-- question: 跳跃游戏
-- method: 贪心

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    bool canJump(vector<int> &nums) {
        int cover = 0;

        for (int i = 0; i <= cover; i++) {
            cover = std::max(cover, i + nums[i]);
            if (cover >= nums.size() - 1) return true;
        }

        return false;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {2, 3, 1, 1, 4};
    bool rel = true;
    IC(nums, rel);

    IC(solution->canJump(nums) == rel);
    // code end

    return 0;
}


