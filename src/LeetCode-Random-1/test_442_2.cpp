/**
执行用时： 36 ms , 在所有 C++ 提交中击败了 93.73% 的用户
内存消耗： 32.7 MB , 在所有 C++ 提交中击败了 80.28% 的用户
通过测试用例： 28 / 28
 */

#include "combofish_utils.hpp"

vector<int> findDuplicates(vector<int> &nums) {
  vec_t res;
  int n = nums.size();
  for (int i = 0; i < n; ++i) {
    int x = std::abs(nums[i]);
    if (nums[x - 1] > 0)
      nums[x - 1] = -nums[x - 1];
    else
      res.emplace_back(x);
  }
  return res;
}

int main() {
  // code start

  vec_t nums = {4, 3, 2, 7, 8, 2, 3, 1};
  IC(nums, findDuplicates(nums));

  return 0;
}
