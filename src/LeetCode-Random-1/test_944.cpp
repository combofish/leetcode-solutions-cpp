/**
-- method: for, for, cnt

--result:
执行用时：36 ms, 在所有 C++ 提交中击败了68.31%的用户
内存消耗：11.8 MB, 在所有 C++ 提交中击败了71.80%的用户
通过测试用例：85 / 85

 */

#include "combofish_utils.hpp"

class Solution {
public:
  // function start.
  int minDeletionSize(vector<string> &strs) {

    int m = strs.size();
    int n = strs[0].size();

    int cnt = 0;

    for (int j = 0; j < n; j++) {
      for (int i = 1; i < m; ++i) {
        if (strs[i][j] < strs[i - 1][j]) {
          cnt++;
          break;
        }
      }
    }

    return cnt;
    ;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  vector<string> strs = {"cba", "daf", "ghi"};
  IC(strs);
  IC(solution->minDeletionSize(strs));
  return 0;
}
