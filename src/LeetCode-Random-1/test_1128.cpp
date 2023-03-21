/**
执行用时：40 ms, 在所有 C++ 提交中击败了80.62%的用户
内存消耗：21.4 MB, 在所有 C++ 提交中击败了92.13%的用户
通过测试用例：19 / 19
 */

#include "combofish_utils.hpp"

int numEquivDominoPairs(vector<vector<int>> &dominoes) {
  int ret = 0;
  vec_t rec(100, 0);

  for (auto &c : dominoes) {
    int n = std::min(c.front(), c.back()) * 10 + std::max(c.front(), c.back());
    ret += rec[n];

    IC(n, ret);

    ++rec[n];
  }

  return ret;
}
int main() {

  // code start

  // mat_t dominoes = {{1, 2}, {2, 1}, {3, 4}, {5, 6}};
  mat_t dominoes = {{2, 1}, {5, 4}, {3, 7}, {6, 2}, {4, 4}, {1, 8},
                    {9, 6}, {5, 3}, {7, 4}, {1, 9}, {1, 1}, {6, 6},
                    {9, 6}, {1, 3}, {9, 7}, {4, 7}, {5, 1}, {6, 5},
                    {1, 6}, {6, 1}, {1, 8}, {7, 2}, {2, 4}, {1, 6},
                    {3, 1}, {3, 9}, {3, 7}, {9, 1}, {1, 9}, {8, 9}}; // 11;

  IC(numEquivDominoPairs(IC(dominoes)));

  return 0;
}
