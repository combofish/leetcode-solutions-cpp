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
    // function start.

private:
    int _count;

    void backtracking(vector<vector<int>> &results, vector<int> &path,
                      int l, int targetSum, int k) {
        // IC(l, path, std::accumulate(path.begin(), path.end(), 0));
//        if (k == path.size()) {
//            if (std::accumulate(path.begin(), path.end(), 0) == targetSum)
//                results.push_back(path);
//            return;
//        }

        int _test_sum = std::accumulate(path.begin(), path.end(), 0);
        if (k == path.size() && targetSum == std::accumulate(path.begin(), path.end(), 0)) {
            results.push_back(path);
            return;
        }
        for (int i = l; i <= 9 - (k - path.size() - 1) && path.size() < k; i++) {
            int _a = i;
            int _b = k - path.size();
            int _c = k - path.size() - 1;
            int _d = 9 - (k - path.size() - 1);
            int _e = 9 - (3 - path.size() - 1);
            int _f = 7 + path.size();
            IC(_a, _b, _c, _d);

            path.push_back(i);
            backtracking(results, path, i + 1, targetSum, k);

            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        _count = 0;
        vector<vector<int>> results;
        vector<int> path;
        backtracking(results, path, 1, n, k);
        return results;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    int k = 3;
    int n = 7;
    vector<vector<int>> mat = {{1, 2, 4}};
    IC(k, n, mat);
    IC(solution->combinationSum3(k, n));
    // code end

    delete solution;
    return 0;
}


