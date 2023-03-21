/**
-- question: 子集
-- method:
 - []

--result:

-- analyse:
Time: O(n * 2^n)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> path;
        result.clear();

        backtracking(nums, 0, path);
        return result;
    }

private:
    vector<vector<int>> result;

    void backtracking(const vector<int> &nums, int idx, vector<int> &path) {
        result.emplace_back(path);

        for (int i = idx; i < nums.size(); i++) {
            path.emplace_back(nums[i]);
            backtracking(nums, i + 1, path);
            path.pop_back();
        }
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}};


    IC(nums, ans);
    IC(solution->subsets(nums));
    // code end

    return 0;
}
