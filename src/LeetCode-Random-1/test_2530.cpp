/**
-- method: size_cmp, while, i, j

--result:
执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
内存消耗： 6.2 MB , 在所有 C++ 提交中击败了 13.67% 的用户
通过测试用例： 1146 / 1146
 */

#include "combofish_utils.hpp"

class Solution {
public:
  // function start.
  bool oneEditAway(string first, string second) {
    if (first.size() == second.size()) {
      // 替换
      int cnt = 0;
      for (int i = 0; i < first.size(); i++) {
        if (first[i] != second[i])
          cnt++;
      }

      return cnt == 1 || cnt == 0;

    } else if (first.size() == second.size() + 1 ||
               first.size() + 1 == second.size()) {

      // 删除
      int i = 0, j = 0;
      bool flag = false;

      while (i < first.size() || j < second.size()) {
        if (first[i] == second[j]) {
          IC(first[i], second[j]);

          i++;
          j++;
        } else {
          if (!flag) {
            IC(i, j);

            flag = true;
            if (first.size() > second.size()) {
              i++;
            } else {
              j++;
            }

            IC(i, j);
          } else {
            return false;
          }
        }
      }
      return true;
    }
    return false;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  string first = "pale";
  string second = "ple";
  IC(first, second);
  IC(solution->oneEditAway(first, second));
  return 0;
}
