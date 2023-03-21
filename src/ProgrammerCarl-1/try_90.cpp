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

    void backtracking(vector<int> &nums, int startIndex) {
        result.push_back(path);
        if (startIndex >= nums.size()) return;

        for (int i = startIndex; i < nums.size(); i++) {
            if (i > startIndex && nums[i] == nums[i - 1]) continue;

            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    // function start.
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        result.clear();
        path.clear();
        std::sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int>
            nums = {1, 2, 2};
    vector<vector<int>> rel = {{},
                               {1},
                               {1, 2},
                               {1, 2, 2},
                               {2},
                               {2, 2}};

    IC(nums, rel);
    IC(solution->subsetsWithDup(nums));

    // code end

    delete solution;
    return 0;
}


