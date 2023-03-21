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
public:
    // function start.

private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &nums, int startIndex) {
        result.push_back(path);

        if (startIndex >= nums.size()) {
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        path.clear();
        result.clear();
        backtracking(nums, 0);
        return result;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {1, 2, 3};
    string rel = "[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]";
    IC(nums, rel);

    vector<vector<int>> res = solution->subsets(nums);
    std::sort(res.begin(), res.end());
    IC(res);

    // code end

    delete solution;
    return 0;
}


