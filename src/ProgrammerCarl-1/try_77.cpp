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
    int _count;
    void backtracking(vector<vector<int>> &result, vector<int> &path, int l, int h, int k) {
        IC(l, h, k, ++_count);

        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        // for (int i = l; i <= h; i++) {
        for (int i = l; i <= h - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtracking(result, path, i + 1, h, k);
            path.pop_back();
        }

    }

public:
    // function start.
    vector<vector<int>> combine(int n, int k) {
        _count = 0;
        vector<vector<int>> result;
        vector<int> path;
        backtracking(result, path, 1, n, k);
        return result;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    int n = 4;
    int k = 2;
    IC(n, k);
    IC(solution->combine(n, k));
    // code end

    delete solution;
    return 0;
}


