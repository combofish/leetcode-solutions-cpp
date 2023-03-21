/**
-- question: 目标和
-- method:
 - [] backtracking
 - [] dp

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
    int findTargetSumWays(vector<int> &nums, int target) {
        result = 0;
        backtracking(nums, target, 0, 0);
        return result;
    }

private:
    int result;

    void backtracking(const vector<int> &nums, int target, int cur, int idx) {
        if (idx >= nums.size()) {
            if (cur == target) result++;
            return;
        }

        backtracking(nums, target, cur + nums[idx], idx + 1);
        backtracking(nums, target, cur - nums[idx], idx + 1);
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int rel = 5;

    IC(nums, target, rel);

    IC(solution->findTargetSumWays(nums, target) == rel);


    // code end

    return 0;
}


