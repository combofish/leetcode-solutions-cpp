/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <set>


class Solution {
private:
    vector<vector<int>> _result;
    vector<int> _path;

    void backtracking(std::vector<int> &candidates, int target, int sum, int idx, vector<bool> &used) {
        if (sum == target) {
            _result.push_back(_path);
            return;
        }

        for (int i = idx; i < candidates.size() && sum + candidates[i] <= target; i++) {

            if (i > 0 && candidates[i] == candidates[i - 1] && !used[i - 1]) continue;

            _path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum + candidates[i], i + 1, used);
            used[i] = false;
            _path.pop_back();
        }
    }

public:
    // function start.
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<bool> used(candidates.size(), false);
        _result.clear();
        _path.clear();
        std::sort(candidates.begin(), candidates.end());

        backtracking(candidates, target, 0, 0, used);
        return _result;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> rel = {
            {1, 1, 6},
            {1, 2, 5},
            {1, 7},
            {2, 6}
    };

    IC(candidates, target, rel);
    IC(solution->combinationSum2(candidates, target));



    // code end

    delete solution;
    return 0;
}


