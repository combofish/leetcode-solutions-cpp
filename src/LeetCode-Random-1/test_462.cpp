/**
-- method: sort

--result:
执行用时：12 ms, 在所有 C++ 提交中击败了48.59%的用户
内存消耗：10.4 MB, 在所有 C++ 提交中击败了95.72%的用户
通过测试用例：30 / 30

-- analyse:
Time: O(nlog n)
Space: O(log n)

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
  // function start.
  int minMoves2(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int ret = 0, x = nums[nums.size() / 2];
    for (auto &i : nums)
      ret += std::abs(i - x);

    return ret;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  vec_t nums = {1, 10, 2, 9};
  IC(nums);
  IC(solution->minMoves2(nums));
  IC(16);

  return 0;
}
