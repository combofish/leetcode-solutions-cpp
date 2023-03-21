/**
 *
 */

#include "combofish_utils.hpp"

int main(int argc, char **argv) {
  vector<int> nums = {1, 2, 3, 1};
  int n = nums.size();
  if (n == 1)
    return nums[0];

  vector<int> dp(n, 0);
  dp[0] = nums[0];
  dp[1] = std::max(nums[0], nums[1]);
  for (int i = 2; i < n; i++) {
    dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
  }

  int res = dp[n - 1];

  out(res);

  return 0;
}
