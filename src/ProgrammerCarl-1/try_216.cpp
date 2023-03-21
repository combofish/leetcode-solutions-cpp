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
    void backtracking(vector<vector<int>> &results, vector<int> &path, int l, int n, int k) {
        if (path.size() == k) {
            if (std::accumulate(path.begin(), path.end(), 0) == n)
                results.push_back(path);
            return;
        }

        for (int i = l; i <= 9 - (k - path.size() - 1); i++) {
            path.push_back(i);
            backtracking(results, path, i + 1, n, k);
            path.pop_back();
        }
    }

public:
    // function start.
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        backtracking(result, path, 1, n, k);
        return result;
    }

    // 2 test
private:
    void backtracking_2(vector<vector<int>> &results, vector<int> &path, int l, int n, int k) {
        if (k == path.size() && std::accumulate(path.begin(), path.end(), 0) == n) {
            results.push_back(path);
            return;
        }

        for (int i = l; i <= 9 - (k - path.size() - 1); i++) {
            path.push_back(i);
            backtracking(results, path, i + 1, n, k);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3_2(int k, int n) {
        vector<vector<int>> results;
        vector<int> path;
        backtracking_2(results, path, 1, n, k);
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
    IC(solution->combinationSum3_2(k, n));
    // code end

    delete solution;
    return 0;
}


