/**
-- method: gap, index

--result:
执行用时：24 ms, 在所有 C++ 提交中击败了84.85%的用户
内存消耗：23.9 MB, 在所有 C++ 提交中击败了94.74%的用户
通过测试用例：102 / 102

-- analyse:
Time: O(n)
Space: O(1)

 */

#include "combofish_utils.hpp"
#include <random>

class Solution {
public:
  // function start.
  int repeatedNTimes(vector<int> &nums) {
    int n = nums.size();
    for (int gap = 1; gap <= 3; gap++) {
      for (int i = 0; i + gap < n; ++i) {
        if (nums[i] == nums[i + gap])
          return nums[i];
      }
    }

    return -1;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  vec_t nums = {5, 1, 5, 2, 5, 3, 5, 4};
  IC(nums);
  IC(solution->repeatedNTimes(nums));
  IC(5);
  return 0;
}
