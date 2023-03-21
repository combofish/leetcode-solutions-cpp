/**
-- method: DP

--result:
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：6.4 MB, 在所有 C++ 提交中击败了37.49%的用户
通过测试用例：63 / 63
 */

#include "combofish_utils.hpp"

class Solution {

public:
  // function start.
  int uniquePaths(int m, int n) {
    vector<vector<int>> f(m, vec_t(n));
    for (int i = 0; i < m; ++i)
      f[i][0] = 1;

    for (int j = 0; j < n; ++j)
      f[0][j] = 1;

    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        f[i][j] = f[i - 1][j] + f[i][j - 1];

    return f[m - 1][n - 1];
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
