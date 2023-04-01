/**
-- question: 最长有效括号
-- method:
 - [-] 动态规划
 - [ ] 栈
 - [ ] 不需要额外的空间

--result:

-- analyse:
Time: O(n)
Space: O(n)
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
        int ans = 0, n = s.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == '(') continue;

            // s[i] == ')'
            if (s[i - 1] == '(')
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] + 1] == '(')
                dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;

            ans = std::max(ans, dp[i]);
        }

        IC(dp);

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


