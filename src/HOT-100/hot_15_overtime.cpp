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

    vector<vector<int>> threeSum(vector<int> &nums) {
        result.clear();
        path.clear();

        std::sort(nums.begin(), nums.end());
        IC(nums);

        vector<bool> used(nums.size(), false);
        backtracking(nums, 0, 0, used);
        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(const vector<int> &nums, int sum, int startIndex, vector<bool>&used) {
        if (path.size() >= 3) {
            if (!sum) result.emplace_back(path);
            return;
        }

        for (int i = startIndex; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i-1]) continue;

            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, sum + nums[i], i + 1, used);
            path.pop_back();
            used[i] = false;
        }
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> rel = {{-1, -1, 2},
                               {-1, 0,  1}};
    IC(nums, rel);
    IC(solution->threeSum(nums));

    // code end

    delete solution;
    return 0;
}


