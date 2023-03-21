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
        int numsSum = std::accumulate(nums.begin(), nums.end(), 0);
        if (std::abs(target) > numsSum) return 0;
        if ((numsSum + target) % 2) return 0;

        int bagSize = (numsSum + target) >> 1;
        if (bagSize < 0) return 0;

        vector<int> dp(bagSize + 1, 0);
        dp.front() = 1;

        for (const auto &item: nums)
            for (int j = bagSize; j >= item; j--)
                dp[j] += dp[j - item];

        return dp.back();

    }

private:
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


