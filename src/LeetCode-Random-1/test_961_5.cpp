/**
-- method: sort, index

--result:
执行用时：28 ms, 在所有 C++ 提交中击败了67.70%的用户
内存消耗：24 MB, 在所有 C++ 提交中击败了85.47%的用户
通过测试用例：102 / 102

-- analyse:
Time: O(n logn)
Space: O(1)

 */

#include "combofish_utils.hpp"
#include <random>

class Solution {
public:
  // function start.
  int repeatedNTimes(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 1; i < n; ++i)
      if (nums[i] == nums[i - 1])
        return nums[i];

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
