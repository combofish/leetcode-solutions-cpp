/**
-- question: 括号生成
-- method:
 - [-] 回朔
 - [ ] 按括号序列的长度递归

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
    vector <string> generateParenthesis(int n) {
        ans.clear();
        string path;
        backtracking(path, n, 0, 0);
        return ans;
    }

private:
    vector <string> ans;

    void backtracking(string &path, int n, int left, int right) {
        if (path.size() >= n * 2) {
            ans.emplace_back(path);
            return;
        }

//        if (right < left) {
//            if (left < n) {
//                path.push_back('(');
//                backtracking(path, n, left + 1, right);
//                path.pop_back();
//            }
//
//            path.push_back(')');
//            backtracking(path, n, left, right + 1);
//            path.pop_back();
//        } else if (right >= left && left < n) {
//            path.push_back('(');
//            backtracking(path, n, left + 1, right);
//            path.pop_back();
//        }


        if (left < n) {
            path.push_back('(');
            backtracking(path, n, left + 1, right);
            path.pop_back();
        }

        if (right < left) {
            path.push_back(')');
            backtracking(path, n, left, right + 1);
            path.pop_back();
        }
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    int n = 3;
    vector <string> ans = {
            "((()))", "(()())", "(())()", "()(())", "()()()"
    };
    IC(n, ans);

    IC(solution->generateParenthesis(n));

    // code end

    return 0;
}


