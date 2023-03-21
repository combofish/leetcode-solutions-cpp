/**
-- question:
-- method:

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
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        result.clear();
        path.clear();
        backtracking(candidates, target, 0);
        return result;
    }

private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(const vector<int> &candidates, int target, int idx) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = idx; i < candidates.size() && target - candidates[i] >= 0; i++) {
            path.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i);
            path.pop_back();
        }

    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> candidates = {2, 3, 5};
    int target = 8;
    vector<vector<int>> rel = {{2, 2, 2, 2},
                               {2, 3, 3},
                               {3, 5}};
    IC(candidates, target, rel);

    IC(solution->combinationSum(candidates, target));
    // code end

    return 0;
}


