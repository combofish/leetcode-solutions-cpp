/**
-- question: 删除无效的括号
-- method:
 - [ ] 回溯 + 剪枝
 - [*] 广度优先搜索
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
        vector<string> ans;
        unordered_set<string> currSet;

        currSet.insert(s);
        while (true) {
            IC(currSet);
            for (const auto &str: currSet) {
                if (isValid(str)) ans.emplace_back(str);
            }
            if (ans.size() > 0) return ans;

            auto nextSet = unordered_set<string>();
            for (const auto &str: currSet) {
                for (int i = 0; i < str.size(); i++) {
                    if (i > 0 && str[i] == str[i - 1]) continue;
                    if (str[i] == '(' || str[i] == ')')
                        nextSet.insert(str.substr(0, i) + str.substr(i + 1));
                }
            }
            currSet = nextSet;
        }
    }

private:
    bool isValid(const string &str) {
        int cnt = 0;
        for (const auto &c: str) {
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
    vector<string> rec = {"(a())()", "(a)()()"};

    IC(s, rec);
    IC(solution->removeInvalidParentheses(s));


    // code end

    return 0;
}
