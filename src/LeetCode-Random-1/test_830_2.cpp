/**
-- method: for, num, count.

--result:
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：7.2 MB, 在所有 C++ 提交中击败了43.24%的用户
通过测试用例：202 / 202
 */

#include "combofish_utils.hpp"

class Solution {
public:
  // function start.
  vector<vector<int>> largeGroupPositions(string s) {
    vector<vector<int>> res;

    int n = s.size();
    int num = 1;

    for (int i = 0; i < s.size(); i++) {
      if (i == n - 1 || s[i] != s[i + 1]) {
        if (num >= 3) {
          res.push_back({i - num + 1, i});
        }
        num = 1;
      } else {
        num++;
      }
    }

    return res;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  string s = "abcdddeeeeaabbbcd";
  IC(s);

  IC(solution->largeGroupPositions(s));
  return 0;
}
