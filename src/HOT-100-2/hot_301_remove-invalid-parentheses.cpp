/**
-- question: 删除无效的括号
-- method:
 - [-] 回溯 + 剪枝
 - [ ] 广度优先搜索
 - [ ] 枚举状态子集

--result:

-- analyse:
Time: O( nxn^2 )
Space: O( n^2 )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    vector<string> removeInvalidParentheses(string s) {
        int lrm = 0, rrm = 0;

        for (const auto &c: s) {
            if (c == '(') lrm++;
            else if (c == ')') {
                if (lrm == 0) {
                    rrm++;
                } else {
                    lrm--;
                }
            }
        }

        helper(s, 0, lrm, rrm);
        return res;
    }

private:
    vector<string> res;

    void helper(string str, int start, int lrm, int rrm) {
        if (lrm == 0 && rrm == 0) {
            if (isValid(str)) res.emplace_back(str);
            return;
        }
        for (int i = start; i < str.size(); i++) {
            if (i != start && str[i] == str[i - 1]) continue;
            if (lrm + rrm > str.size() - i) return;
            if (lrm > 0 && str[i] == '(')
                helper(str.substr(0, i) + str.substr(i + 1), i, lrm - 1, rrm);

            if (rrm > 0 && str[i] == ')')
                helper(str.substr(0, i) + str.substr(i + 1), i, lrm, rrm - 1);
        }

    }

    inline bool isValid(const string &str) {
        int cnt = 0;
        for (auto &c: str) {
            if (c == '(') ++cnt;
            else if (c == ')') {
                --cnt;
                if (cnt < 0) return false;
            }
        }
        return cnt == 0;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "(a)())()";

    vector<string> ans = {"(a())()", "(a)()()"};

    IC(s, ans);

    IC(solution->removeInvalidParentheses(s));

    // code end

    return 0;
}
