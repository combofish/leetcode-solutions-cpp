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
    bool canPartition(vector<int> &nums) {
        int numsSum = std::accumulate(nums.begin(), nums.end(), 0);
        if (numsSum % 2) return false;

        int halfSum = numsSum / 2;
        IC(halfSum, numsSum);

        vector<int> dp(10001, 0);
        for (int i = 0; i < nums.size(); i++)
            for (int j = halfSum; j >= nums[i]; j--)
                dp[j] = std::max(dp[j], dp[j - nums[i]] + nums[i]);

        // out
        for(int i = 0; i< 10; i++)
            IC(dp[i]);
        return dp[halfSum] == halfSum;
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start

    vector<int> nums = {1, 5, 11, 5};
    bool rel = true;
    IC(nums, rel);
    IC(solution->canPartition(nums));
    // code end

    delete solution;
    return 0;
}


