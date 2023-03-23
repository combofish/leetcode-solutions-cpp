/**
-- question: 目标和
-- method:
 - [ ] 回溯
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
    void backtracking(const vector<int> &vec, int i, int target) {
        if (i >= vec.size()) {
            if (!target) ++ans;
            return;
        }
        backtracking(vec, i + 1, target + vec[i]);
        backtracking(vec, i + 1, target - vec[i]);
    }

    int findTargetSumWays(vector<int> &nums, int target) {
        ans = 0;
        backtracking(nums, 0, target);
        return ans;
    }

private:
    int ans;
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int ans = 5;
    IC(nums, target, ans);

    IC(solution->findTargetSumWays(nums, target));

    // code end

    return 0;
}


