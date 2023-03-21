/**
-- method: dfs

--result:

 */

#include "combofish_utils.hpp"

class Solution {
  int m, n;
  int dirs[2][2] = {{+1, 0}, {0, +1}};

  void dfs(int i, int j, int &count) {
    if (i == m - 1 && j == n - 1) {
      count++;
      return;
    }

    for (int k = 0; k < 2; ++k) {
      int new_i = i + dirs[k][0];
      int new_j = j + dirs[k][1];

      if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {

        // IC(i, j, new_i, new_j, count);
        dfs(new_i, new_j, count);
      }
    }
  }

public:
  // function start.
  int uniquePaths(int m, int n) {
    this->m = m;
    this->n = n;

    int ret = 0;
    dfs(0, 0, ret);
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
