/**
执行用时： 4 ms , 在所有 C++ 提交中击败了 42.67% 的用户
内存消耗： 8.9 MB , 在所有 C++ 提交中击败了 30.68% 的用户
通过测试用例： 59 / 59
 */

#include "combofish_utils.hpp"
#include <algorithm>

void merge(vector<int> &A, int m, vector<int> &B, int n) {

  for (int i = m; i < A.size(); ++i)
    A[i] = B[i - m];

  std::sort(A.begin(), A.end());
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
