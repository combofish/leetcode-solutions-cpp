/**
-- question: 跳跃游戏
-- method:

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    bool canJump(vector<int> &nums) {
        return backtrack(nums, 0);
    }

private:

    bool backtrack(const vector<int> &nums, int idx) {

        if (idx >= nums.size() - 1) return true;
        
        bool result = false;
        for (int i = 1; i <= nums[idx]; i++) {
            result |= backtrack(nums, idx + i);
            if(result) return result;
        }
        return result;
    }
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


