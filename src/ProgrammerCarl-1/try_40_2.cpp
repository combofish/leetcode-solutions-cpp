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

    void backtracking(vector<int> &candidates, int target, int sum, int startIndex, vector<bool> &used) {

        if (sum > target) return;
        if (sum == target) {
            result.push_back(path);
            return;
        }

        unordered_set<int> uset;
        for (int i = startIndex; i < candidates.size() && candidates[i] + sum <= target; i++) {

//            if (i > startIndex && candidates[i] == candidates[i - 1] && !used[i - 1]) {
//                continue;
//            }
            if (uset.find(candidates[i]) != uset.end()) continue;

            uset.insert(candidates[i]);
            used[i] = true;
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum + candidates[i], i + 1, used);

            path.pop_back();
            used[i] = false;

        }
    }

    void backtracking_2(vector<int> &candidates, int target, int sum, int startIndex) {
        if (sum > target) return;
        if (sum == target) {
            result.push_back(path);
            return;
        }

        unordered_set<int> uset;
        for (int i = startIndex; i < candidates.size() && candidates[i] + sum <= target; i++) {
            if (uset.find(candidates[i]) != uset.end()) continue;
            uset.insert(candidates[i]);
            path.push_back(candidates[i]);
            backtracking_2(candidates, target, sum + candidates[i], i + 1);
            path.pop_back();
        }
    }

    // function start.
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        path.clear();
        result.clear();
        std::sort(candidates.begin(), candidates.end());


//        vector<bool> used(candidates.size(), false);
//        backtracking(candidates, target, 0, 0, used);

        backtracking_2(candidates, target, 0, 0);
        return result;
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


