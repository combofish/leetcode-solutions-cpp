/**
-- question: 最长有效括号
-- method: stack

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    int longestValidParentheses(string s) {
        int result = 0;
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(i);
            else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    result = std::max(result, i - st.top());
                }
            }

            out_sta(st);
        }

        return result;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = ")))()())";
    int rel = 4;
    IC(s, rel);
    IC(solution->longestValidParentheses(s) == rel);

    // code end

    return 0;
}


