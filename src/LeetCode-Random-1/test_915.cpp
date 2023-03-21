/**
执行用时：196 ms, 在所有 C++ 提交中击败了5.31%的用户
内存消耗：92.1 MB, 在所有 C++ 提交中击败了67.81%的用户
通过测试用例：66 / 66

>>> change nums.front() to nums[0]
执行用时：124 ms, 在所有 C++ 提交中击败了69.69%的用户
内存消耗：92.1 MB, 在所有 C++ 提交中击败了66.88%的用户
通过测试用例：66 / 66
 */

#include "combofish_utils.hpp"
#include <algorithm>

int partitionDisjoint(vector<int> &nums) {
  int all_max = nums[0], left_max = nums[0];
  int idx = 0;

  for (int j = 1; j < nums.size(); ++j) {
    int cur_n = nums[j];
    all_max = std::max(all_max, cur_n);

    if (cur_n < left_max) {
      idx = j;
      left_max = all_max;
    }
  }
  return idx + 1;
}

int main() {
  // code start
  vec_t nums = {5, 0, 3, 5};
  IC(nums);

  IC(partitionDisjoint(nums));
  return 0;
}
