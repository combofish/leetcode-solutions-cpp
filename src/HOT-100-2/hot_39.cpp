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
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        results.clear();
        sort(candidates.begin(), candidates.end());

        vector<int> path;
        backtracking(candidates, 0, path, target);

        return results;
    }


private:
    vector<vector<int>> results;

    void backtracking(vector<int> &candidates, int idx, vector<int> &path, int cur) {
        IC(idx, path, cur);
        if (cur == 0) {
            results.emplace_back(path);
            return;
        }
        if (idx >= candidates.size() || cur < 0) return;

        for (int i = idx; i < candidates.size() && cur >= candidates[i]; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1]) continue;

            path.emplace_back(candidates[i]);
            backtracking(candidates, i, path, cur - candidates[i]);
            path.pop_back();
        }
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> results = {{2, 2, 3}, {7}};

    IC(candidates, target, results);

    IC(solution->combinationSum(candidates, target));
    // code end

    return 0;
}
