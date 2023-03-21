/**
-- method: for, sta, substr

--result:
执行用时：4 ms, 在所有 C++ 提交中击败了65.01%的用户
内存消耗：6.5 MB, 在所有 C++ 提交中击败了62.18%的用户
通过测试用例：59 / 59

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"

class Solution {
public:
  // function start.
  string removeOuterParentheses(string s) {
    string ret = "";
    stack<char> sta;
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
      if (i == 0) {
        sta.emplace(s[i]);
        continue;
      }

      if (s[i] == '(') {
        sta.emplace('(');
      }

      if (s[i] == ')') {
        if (sta.top() == '(') {
          sta.pop();
        }

        if (sta.empty()) {
          string sub_s = s.substr(j, i + 1 - j);
          ret += sub_s.substr(1, sub_s.size() - 2);
          IC(i);
          j = i + 1;
        }
      }
    }

    return ret;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  string s = "(()())(())(()(()))";
  string ret = "()()()()(())";

  IC(s);
  IC(solution->removeOuterParentheses(s));
  IC(ret);
  return 0;
}
