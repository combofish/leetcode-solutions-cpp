/**
-- method: long sum, left--, right++

--result:
执行用时：96 ms, 在所有 C++ 提交中击败了48.96%的用户
内存消耗：76.4 MB, 在所有 C++ 提交中击败了95.50%的用户
通过测试用例：78 / 78
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
  // function start.
  int minimumAverageDifference(vector<int> &nums) {
    int n = nums.size();
    long val = std::accumulate(nums.begin(), nums.end(), 0);

    int ret = n - 1;
    long res_val = val / n;

    int left_val = 0;
    for (int i = n - 1; i > 0; i--) {
      left_val += nums[i];
      val -= nums[i];

      long local_val = std::abs(val / i - left_val / (n - i));

      IC(i, left_val, left_val / (n - i), val, val / i, local_val);
      if (local_val <= res_val) {
        res_val = local_val;
        ret = i - 1;
      }
    }

    return ret;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start

  vec_t nums = {2, 5, 3, 9, 5, 3};
  //   vec_t nums = {0, 0, 0, 0}; // 0
  //  vec_t nums = {4, 2, 0};
  IC(nums);

  IC(solution->minimumAverageDifference(nums));
  return 0;
}
