/**
-- question: 分割等和子集
-- method:
 - [ ]
 - [ ] 动态规划


--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    bool canPartition(vector<int> &nums) {
        auto numSum = std::accumulate(nums.begin(), nums.end(), 0);
        if (numSum % 2) return false;

        numSum /= 2;
        int n = nums.size();
        vector<bool> used(n, false);
        ans = false;
        for (int i = 0; i < n; i++) {
            used[i] = true;
            backtracking(nums, used, i, numSum - nums[i]);
            used[i] = false;
        }

        return ans;
    }

private:
    bool ans;

    void backtracking(const vector<int> &nums, vector<bool> &used, int idx, int target) {
        if (!target) {
            ans = true;
            return;
        }
        // if (ans) return;

        for (int i = idx + 1; i < nums.size() && !ans; i++) {
            if (used[i]) continue;

            used[i] = true;
            backtracking(nums, used, i, target - nums[i]);
            used[i] = false;
        }
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> nums = {1, 5, 11, 5};
    bool ans = true;

    IC(nums, ans);

    IC(solution->canPartition(nums));

    // code end

    return 0;
}


