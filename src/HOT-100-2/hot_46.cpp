/**
-- question:
-- method:
 - []

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
    vector<vector<int>> permute(vector<int> &nums) {
        results.clear();

        vector<bool> used(nums.size(), false);

        vector<int> path;
        backtracking(nums, used, path);
        return results;
    }

private:
    vector<vector<int>> results;

    void backtracking(vector<int> &nums, vector<bool> &used, vector<int> &path) {
        if (path.size() >= nums.size()) {
            results.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            path.emplace_back(nums[i]);
            used[i] = true;

            backtracking(nums, used, path);

            used[i] = false;
            path.pop_back();
        }
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};

    IC(nums, result);

    IC(solution->permute(nums));
    // code end

    return 0;
}
