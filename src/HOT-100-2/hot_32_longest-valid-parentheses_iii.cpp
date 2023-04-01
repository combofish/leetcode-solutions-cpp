/**
-- question: 最长有效括号
-- method:
 - [ ] 动态规划
 - [ ] 栈
 - [-] 不需要额外的空间

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>


/**
 * not try
 */
class Solution {

    // function start.
public:

    int longestValidParentheses(string s) {
        int ans = 0;
        int n = s.size();
        int lk = 0, rk = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') ++lk;
            else ++rk;

            if (lk == rk) ans = std::max(ans, lk * 2);
            else if (rk > lk) lk = rk = 0;
        }

        lk = rk = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') lk++;
            else rk++;

            if (lk == rk) ans = std::max(ans, lk * 2);
            else if (lk > rk) lk = rk = 0;
        }


        return ans;

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = ")()())";
    int ans = 4;

    IC(s, ans);

    IC(solution->longestValidParentheses(s));
    // code end

    return 0;
}


