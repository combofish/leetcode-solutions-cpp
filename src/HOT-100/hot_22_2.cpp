/**
-- method: 括号序列的长度递归

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <memory>

class Solution {

    // function start.
public:
    vector<string> generateParenthesis(int n) {
        return *generate(n);
    }

    ~Solution(){
        IC("delete");
    }

private:
    std::shared_ptr<vector<string>> cache[100] = {nullptr};

    std::shared_ptr<vector<string>> generate(int n) {
        if (cache[n])return cache[n];
        if (n == 0) cache[0] = std::make_shared<vector<string>>(vector<string>{""});
        else {
            auto result = std::make_shared<vector<string>>();
            for (int i = 0; i != n; ++i) {
                auto lefts = generate(i);
                auto rights = generate(n - i - 1);
                for (const string &left: *lefts)
                    for (const string &right: *rights)
                        result->push_back("(" + left + ")" + right);

            }
            cache[n] = result;
        }

        return cache[n];
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


