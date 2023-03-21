/**
-- method: for, for, count.

--result:
执行用时：32 ms, 在所有 C++ 提交中击败了34.26%的用户
内存消耗：9.8 MB, 在所有 C++ 提交中击败了73.56%的用户
通过测试用例：103 / 103
 */

#include "combofish_utils.hpp"

class Solution {
public:
  // function start.
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    int n = nums.size();
    vec_t res(n);

    for (int i = 0; i < n; i++) {
      int cur_n = nums[i];

      int count = 0;
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        if (nums[j] < nums[i]) {
          count++;
        }
      }

      res[i] = count;
    }
    return res;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  vec_t nums = {8, 1, 2, 2, 3};
  IC(nums);
  IC(solution->smallerNumbersThanCurrent(nums));
  return 0;
}
