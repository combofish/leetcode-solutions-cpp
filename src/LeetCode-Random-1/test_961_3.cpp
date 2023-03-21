/**
-- method: random select

--result:
执行用时：28 ms, 在所有 C++ 提交中击败了67.70%的用户
内存消耗：24.1 MB, 在所有 C++ 提交中击败了46.52%的用户
通过测试用例：102 / 102

-- analyse:
Time: O(1)
Space: O(1)

 */

#include "combofish_utils.hpp"
#include <random>

class Solution {
public:
  // function start.
  int repeatedNTimes(vector<int> &nums) {
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> dis(0, nums.size() - 1);

    while (true) {
      int x = dis(gen), y = dis(gen);
      if (x != y && nums[x] == nums[y])
        return nums[x];
    }
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
