/**
-- question: 删除无效的括号
-- method:
 - [*] 回溯 + 剪枝
 - [ ] 广度优先搜索
 - [ ] 枚举状态子集

--result:

-- analyse:
Time: O(n * 2^n)
Space: O(n^2)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<string> removeInvalidParentheses(string s) {
        int lRemove = 0;
        int rRemove = 0;

        for (const auto &c: s) {
            if (c == '(') lRemove++;
            else if (c == ')') {
                if (lRemove) lRemove--;
                else
                    rRemove++;
            }
        }
        IC(lRemove, rRemove);

        helper(s, 0, lRemove, rRemove);
        return res;
    }

private:
    vector<string> res;
    void helper(string str, int start, int lRemove, int rRemove) {
        IC(str, start, lRemove, rRemove);
	
        if (!lRemove && !rRemove) {
            if (isValid(str)) res.emplace_back(str);
            return;
        }

        for (int i = start; i < str.size(); i++) {
            if (i != start && str[i] == str[i - 1]) continue;

            // 如果剩余的字符无法满足去掉的数量要求，直接返回
            if (lRemove + rRemove > str.size() - i) return;

            if (lRemove > 0 && str[i] == '(') helper(str.substr(0, i) + str.substr(i + 1), i, lRemove - 1, rRemove);
            if (rRemove > 0 && str[i] == ')') helper(str.substr(0, i) + str.substr(i + 1), i, lRemove, rRemove - 1);
        }
    }

    inline bool isValid(const string &str) {
        int cnt = 0;
        for (const auto &c: str) {
            if (c == '(') ++cnt;
            else if (c == ')') {
                --cnt;
                if (cnt < 0) return false;
            }
        }

        return 0 == cnt;
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "(a)())()";
    vector<string> rec = {"(a())()", "(a)()()"};

    IC(s, rec);
    IC(solution->removeInvalidParentheses(s));


    // code end

    return 0;
}
