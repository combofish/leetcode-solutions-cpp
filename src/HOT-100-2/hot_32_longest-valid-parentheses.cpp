/**
-- question: 最长有效括号
-- method:
 - [ ] 动态规划
 - [-] 栈
 - [ ] 不需要额外的空间

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    int longestValidParentheses(string s) {
        int n = s.size();
        if (!n) return 0;

        int ans = 0;
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) st.push(i);
                else {
                    ans = std::max(ans, i - st.top());
                }
            }
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


