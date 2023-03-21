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
    int result;

    void backtracking(int curIndex, vector<int> &nums, int step) {
        if (curIndex >= nums.size() - 1) {
            result = std::min(step, result);
            return;
        }

        for (int i = 1; i <= nums[curIndex]; i++) {
            backtracking(curIndex + i, nums, step + 1);
        }
    }

    // function start.
public:

    int jump(vector<int> &nums) {
        result = INT_MAX;
        backtracking(0, nums, 0);
        return result;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {2, 3, 1, 1, 4};
    int rel = 2;
    IC(nums, rel);

    IC(solution->jump(nums));

    vector<int> nums2 = {5, 6, 4, 4, 6, 9, 3, 8, 5};

    IC(solution->jump(nums2));
    // code end

    delete solution;
    return 0;
}


