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
    // function start.


public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int numsSum = std::accumulate(nums.begin(), nums.end(), 0);
        if (std::abs(target) > numsSum) return 0;
        if ((target + numsSum) % 2) return 0;

        int bagSize = (target + numsSum) / 2;
        if (bagSize < 0) return 0;
        IC(bagSize);

        vector<int> dp(bagSize+1, 0);
        dp[0] = 1;


        for(int num : nums) {
            for (int j = bagSize; j >= num; j--)
                dp[j] += dp[j - num];

            IC(dp);
        }
        return dp.back();

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
    IC(solution->findTargetSumWays(nums, target) == rel);

    // code end

    delete solution;
    return 0;
}


