/**
-- method: lib_sort

--result:
执行用时：36 ms, 在所有 C++ 提交中击败了98.73%的用户
内存消耗：27.8 MB, 在所有 C++ 提交中击败了63.19%的用户
通过测试用例：13 / 13
 */

#include "combofish_utils.hpp"

vector<int> sortArray(vector<int> &nums) {
  std::sort(nums.begin(), nums.end());
  return nums;
}

int main() {
  // code start

  vec_t nums = {5, 2, 3, 1};
  IC(nums);
  IC(sortArray(nums));

  return 0;
}
