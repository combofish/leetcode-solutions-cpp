/**
执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
内存消耗： 8.7 MB , 在所有 C++ 提交中击败了 84.13% 的用户
通过测试用例： 59 / 59
 */

#include "combofish_utils.hpp"
#include <algorithm>

void merge(vector<int> &A, int m, vector<int> &B, int n) {
  int i = m - 1, j = n - 1, idx = A.size() - 1;
  while (i >= 0 || j >= 0)
    if (i == -1)
      A[idx--] = B[j--];
    else if (j == -1)
      A[idx--] = A[i--];
    else if (A[i] < B[j])
      A[idx--] = B[j--];
    else
      A[idx--] = A[i--];
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
