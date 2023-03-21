/**
-- method: recursive

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
    vector<string> generateParenthesis(int n) {
        result.clear();
        path.clear();
        backtracking(0, 0, n);
        return result;
    }

private:
    vector<string> result;
    string path;

    void backtracking(int open, int close, int n) {
        if (path.size() == n * 2) {
            result.push_back(path);
            return;
        }

        if (open < n) {
            path.push_back('(');
            backtracking(open + 1, close, n);
            path.pop_back();
        }
        if (close < open) {
            path.push_back(')');
            backtracking(open, close + 1, n);
            path.pop_back();
        }
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int n = 3;
    vector<string> rel = {"((()))", "(()())", "(())()", "()(())", "()()()"};

    IC(n, rel);
    IC(solution->generateParenthesis(n));
    // code end

    return 0;
}


