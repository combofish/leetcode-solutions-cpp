/**
-- question: 括号生成
-- method:
 - [ ] 回朔
 - [-] 按括号序列的长度递归

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
    vector<string> generateParenthesis(int n) {
        return *generate(n);
    }

private:

    std::shared_ptr<vector<string>> cache[100] = {nullptr};

    std::shared_ptr<vector<string>> generate(int n) {
        if (cache[n]) return cache[n];
        if (!n) {
            cache[0] = std::make_shared<vector<string>>(vector<string>{""});
        } else {
            auto res = std::make_shared<vector<string>>();
            for (int i = 0; i != n; i++) {
                auto lefts = generate(i);
                auto rights = generate(n - i - 1);
                for (const auto &left: *lefts) {
                    for (const auto &right: *rights) {
                        res->push_back("(" + left + ")" + right);
                    }
                }
            }
            IC(*res);
            cache[n] = res;
        }
        return cache[n];
    }



    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    int n = 3;
    vector<string> ans = {
            "((()))", "(()())", "(())()", "()(())", "()()()"
    };
    IC(n, ans);

    IC(solution->generateParenthesis(n));

    // code end

    return 0;
}


