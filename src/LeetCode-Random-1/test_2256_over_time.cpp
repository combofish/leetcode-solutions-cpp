/**
-- method:

--result:

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
  // function start.
  int minimumAverageDifference(vector<int> &nums) {
    int n = nums.size();

    int res_idx = n - 1;
    int res_val = std::accumulate(nums.begin(), nums.end(), 0) / n;

    for (int i = n - 2; i >= 0; i--) {

      int r = std::accumulate(nums.begin(), nums.begin() + i + 1, 0);
      int l = std::accumulate(nums.begin() + i + 1, nums.end(), 0);

      int r1 = r / (i + 1);
      int l1 = l / (n - i - 1);

      int local_val = std::abs(l1 - r1);

      IC(i, r, (i + 1), l, (n - i - 1), r1, l1, local_val);

      if (local_val <= res_val) {
        res_val = local_val;
        res_idx = i;
      }
    }

    return res_idx;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start

  //   vec_t nums = {2, 5, 3, 9, 5, 3};
  //   vec_t nums = {0, 0, 0, 0}; // 0
  vec_t nums = {4, 2, 0};
  IC(nums);

  IC(solution->minimumAverageDifference(nums));
  return 0;
}
