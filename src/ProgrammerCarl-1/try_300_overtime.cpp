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

    // function start.
public:

    int lengthOfLIS(vector<int> &nums) {
        result = 0;
        backtracking(nums, 0, INT_MIN, 0);
        return result;
    }

private:
    void backtracking(vector<int> &nums, int startIndex, int pre, int count) {
        if (startIndex >= nums.size()) {
            result = std::max(result, count);
            return;
        }


        for (int i = startIndex; i < nums.size(); i++) {
            if (nums[i] > pre) {
                IC(pre, nums[i], count);
                backtracking(nums, i + 1, nums[i], count + 1);
            } else {
                result = std::max(result, count);
            }
        }
    }

    int result;
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int rel = 4;
    IC(nums, rel);
    IC(solution->lengthOfLIS(nums) == rel);

    IC();
    vector<int> nums_2 = {0, 1, 0, 3, 2, 3};
    int rel_2 = 4;
    IC(nums_2, rel_2);
    IC(solution->lengthOfLIS(nums_2));


    IC();
    vector<int> nums_3 = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    int rel_3 = 6;
    IC(nums_3, rel_3);
    IC(solution->lengthOfLIS(nums_3) == rel_3);

    // code end

    delete solution;
    return 0;
}


