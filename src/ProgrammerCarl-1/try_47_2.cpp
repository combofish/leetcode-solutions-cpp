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
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &nums, vector<bool> &used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        unordered_set<int> uset;
        for (int i = 0; i < nums.size(); i++) {
            if(uset.find(nums[i]) != uset.end()) continue;

//            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            // if (i > 0 && nums[i] == nums[i - 1] && used[i - 1]) continue;
            if (!used[i]) {
                uset.insert(nums[i]);
                path.push_back(nums[i]);
                used[i] = true;
                backtracking(nums, used);
                used[i] = false;
                path.pop_back();
            }
        }
    }
    // function start.
public:

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        std::sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return result;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> rel = {{1, 1, 2},
                               {1, 2, 1},
                               {2, 1, 1}};
    IC(nums, rel);

    IC(solution->permuteUnique(nums));
    // code end

    delete solution;
    return 0;
}


