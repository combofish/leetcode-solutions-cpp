/**
-- method: 组合数学

--result:
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了86.49%的用户
通过测试用例：63 / 63
 */

#include "combofish_utils.hpp"

class Solution {

public:
  // function start.
  int uniquePaths(int m, int n) {
    long long ret = 1;

    for (int x = n, y = 1; y < m; ++x, ++y)
      ret = ret * x / y;

    return ret;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  int m = 23, n = 12;
  IC(m, n);
  IC(solution->uniquePaths(m, n) == 193536720);

  return 0;
}
