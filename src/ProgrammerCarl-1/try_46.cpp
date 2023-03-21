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
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, vector<bool> &used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }


    }
    // function start.
public:
    vector<vector<int>> permute(vector<int> &nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> rel = {{1, 2, 3},
                               {1, 3, 2},
                               {2, 1, 3},
                               {2, 3, 1},
                               {3, 1, 2},
                               {3, 2, 1}};

    IC(nums, rel);
    IC(solution->permute(nums));
    // code end

    delete solution;
    return 0;
}


