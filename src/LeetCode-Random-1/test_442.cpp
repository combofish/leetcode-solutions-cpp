/**
执行用时： 104 ms , 在所有 C++ 提交中击败了 5.76% 的用户
内存消耗： 41.6 MB , 在所有 C++ 提交中击败了 12.82% 的用户
通过测试用例： 28 / 28
 */

#include "combofish_utils.hpp"

vector<int> findDuplicates(vector<int> &nums) {
  vec_t res;

  unordered_set<int> uset;
  for (const int &i : nums) {
    if (uset.find(i) != uset.end()) {
      res.emplace_back(i);
      uset.erase(i);
    } else {
      uset.insert(i);
    }
  }
  return res;
}

int main() {
  // code start

  vec_t nums = {4, 3, 2, 7, 8, 2, 3, 1};
  IC(nums, findDuplicates(nums));

  return 0;
}
