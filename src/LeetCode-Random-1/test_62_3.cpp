/**
-- method: DP_v2, 优化空间复杂度

--result:
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：6 MB, 在所有 C++ 提交中击败了67.38%的用户
通过测试用例：63 / 63
 */

#include "combofish_utils.hpp"

class Solution {

public:
  // function start.
  int uniquePaths(int m, int n) {
    vector<int> f(n);

    for (int j = 0; j < n; ++j)
      f[j] = 1;

    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        f[j] += f[j - 1];

    return f[n - 1];
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  int m = 23, n = 12;
  IC(m, n);
  IC(solution->uniquePaths(m, n) == 193536720);

  // 2,3
  // 1, 1, 1
  // 1, 2, 3
  // 1, 3, 6

  return 0;
}
