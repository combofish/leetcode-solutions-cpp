/**
-- question: 全排列
-- method: 回溯

--result:

-- analyse:
Time: O(n*n!)
Space: O(n)
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<vector<int>> permute(vector<int> &nums) {
        path.clear();
        result.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }

private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(const vector<int> nums, vector<bool> &used) {
        if (path.size() >= nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if(used[i]) continue;

            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }

    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

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

    return 0;
}


