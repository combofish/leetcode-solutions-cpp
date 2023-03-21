/**
-- method: uset, count

--result:
执行用时：32 ms, 在所有 C++ 提交中击败了52.86%的用户
内存消耗：24.1 MB, 在所有 C++ 提交中击败了47.60%的用户
通过测试用例：102 / 102

-- analyse:
Time: O(n)
Space: O(n)

 */

#include "combofish_utils.hpp"

class Solution {
public:
  // function start.
  int repeatedNTimes(vector<int> &nums) {
    unordered_set<int> uset;
    for (auto &n : nums) {
      if (uset.count(n)) {
        return n;
      }
      uset.insert(n);
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
