/**
执行用时：68 ms, 在所有 C++ 提交中击败了53.23%的用户
内存消耗：59.8 MB, 在所有 C++ 提交中击败了65.17%的用户
通过测试用例：97 / 97
 */

#include "combofish_utils.hpp"

int numSubarrayProductLessThanK(vector<int> &nums, int k) {
  if (k == 0)
    return 0;

  int n = nums.size(), ret = 0;
  int prod = 1, i = 0;
  for (int j = i; j < n; ++j) {
    prod *= nums[j];
    while (i <= j && prod >= k) {
      prod /= nums[i];
      ++i;
    }

    ret += j - i + 1;
  }

  return ret;
}
int main() {
  // vec_t nums  {0,5, 2, 6};
  // int k =   100;
  vec_t nums(30000, 1);

  int k = 945094;
  IC(nums.size(), k);
  IC(numSubarrayProductLessThanK(nums, k)); // 450015000

  return 0;
}
