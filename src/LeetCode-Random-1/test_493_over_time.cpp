/**
-- method: for, for, Err for overtime

--result:

 */

#include "combofish_utils.hpp"

int reversePairs(vector<int> &nums) {
  if (nums.size() == 1)
    return 0;
  int ret = 0;
  int n = nums.size();

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; ++j) {

      if (nums[i] > 2 * (long)nums[j]) {
        IC(i, j);
        ++ret;
      }
    }
  }

  return ret;
}

int main() {
  // code start
  //   vec_t nums = {1, 3, 2, 3, 1};
  vec_t nums = {2147483647, 2147483647, 2147483647,
                2147483647, 2147483647, 2147483647};
  IC(nums, reversePairs(nums));
  return 0;
}
