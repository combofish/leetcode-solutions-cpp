/**
-- question: 子集
-- method: 回溯
 - []

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
    vector<vector<int>> subsets(vector<int> &nums) {
        result.clear();
        path.clear();

        backtracking(nums, 0);
        return result;
    }

private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(const vector<int> &nums, int idx) {
//        if (idx > nums.size()) return;

        result.push_back(path);

        for (int i = idx; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> rel = {{},
                               {1},
                               {2},
                               {1, 2},
                               {3},
                               {1, 3},
                               {2, 3},
                               {1, 2, 3}};

    IC(nums, rel);
    IC(solution->subsets(nums));
    // code end

    return 0;
}


