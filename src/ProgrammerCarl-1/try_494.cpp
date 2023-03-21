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
    int count;

    // function start.
    void backtracking(vector<int> &nums, int target, int startIndex, int sum) {
        if (startIndex >= nums.size()) {
            if (sum == target) count++;
            return;
        }

        backtracking(nums, target, startIndex + 1, sum + nums[startIndex]);
        backtracking(nums, target, startIndex + 1, sum - nums[startIndex]);
    }

public:
    int findTargetSumWays(vector<int> &nums, int target) {
        // cut off
        int numsSum = std::accumulate(nums.begin(), nums.end(), 0);
        if (std::abs(target) > numsSum) return 0;
        if ((numsSum + target) % 2) return 0;


        count = 0;
        backtracking(nums, target, 0, 0);
        return count;
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int rel = 5;

    IC(nums, target, rel);
    IC(solution->findTargetSumWays(nums, target));

    // code end

    delete solution;
    return 0;
}


