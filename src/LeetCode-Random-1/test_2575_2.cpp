/**
执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
内存消耗： 8.9 MB , 在所有 C++ 提交中击败了 26.50% 的用户
通过测试用例： 59 / 59
 */

#include "combofish_utils.hpp"
#include <algorithm>

void merge(vector<int> &A, int m, vector<int> &B, int n) {
  vector<int> res;
  int i = 0, j = 0;
  while (i < m || j < n) {
    while (i < m && j == n)
      res.emplace_back(A[i++]);

    while (i == m && j < n)
      res.emplace_back(B[j++]);

    while (i < m && j < n)
      if (A[i] < B[j])
        res.emplace_back(A[i++]);
      else
        res.emplace_back(B[j++]);
  }

  for (int i = 0; i < A.size(); ++i)
    A[i] = res[i];
}
int main() {
  // code start
  vec_t A = {1, 2, 3, 0, 0, 0};
  vec_t B = {2, 5, 6};

  int m = 3;
  int n = 3;

  IC(A, B);
  merge(A, m, B, n);

  IC(A);
  return 0;
}
