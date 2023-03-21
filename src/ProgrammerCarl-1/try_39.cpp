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
    vector<vector<int>> _results;
    vector<int> _path;

    void backtracking(vector<int> &candidates, int target, int sum, int idx) {
        // if (sum > target) return;
        if (sum == target) {
            _results.push_back(_path);
            return;
        }

        for (int i = idx; i < candidates.size() && sum + candidates[i] <= target; i++) {
            _path.push_back(candidates[i]);
            backtracking(candidates, target, sum + candidates[i], i );
            _path.pop_back();
        }
    }

public:
    // function start.
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        _results.clear();
        _path.clear();
        std::sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return _results;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> rel = {{2, 2, 3},
                               {7}};

    IC(candidates, target, rel);
    IC(solution->combinationSum(candidates, target));

    // code end

    delete solution;
    return 0;
}


