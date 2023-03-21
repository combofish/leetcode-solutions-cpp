

#include "combofish_utils.hpp"
int numSubarrayProductLessThanK(vector<int> &nums, int k) {
  int n = nums.size();
  int res = 0;

  for (int i = 0; i < n; i++) {
    int dot = 1;

    for (int j = i; j < n; ++j) {
      dot *= nums[j];
      if (dot < k) {
        IC(i, j, nums[i], nums[j], j - i + 1);

        ++res;
      } else {
        break;
      }
    }
  }

  return res;
}
int main() {
  vec_t nums = {10, 5, 2, 6};
  int k = 100;
  IC(nums, k);
  IC(numSubarrayProductLessThanK(nums, k));

  return 0;
}
