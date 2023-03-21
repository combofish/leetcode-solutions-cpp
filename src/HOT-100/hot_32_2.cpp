/**
-- question: 最长有效括号
-- method: left, right

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    int longestValidParentheses(string s) {
        int left = 0, right = 0, result = 0;

        for (char i : s) {
            if (i == '(') left++;
            else right++;

            if (left == right) result = std::max(result, right + left);
            else if (right > left) left = right = 0;
        }

        left = right = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else right++;

            if (left == right) result = std::max(result, right + left);
            else if (left > right) left = right = 0;
        }

        return result;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
//    string s = ")))()())";
//    int rel = 4;
    string s = "(()";
    int rel = 2;
    IC(s, rel);
    IC(solution->longestValidParentheses(s) == rel);

    // code end

    return 0;
}


