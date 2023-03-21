/**
-- method: cnt sort

--result:
执行用时：4 ms, 在所有 C++ 提交中击败了91.98%的用户
内存消耗：9.8 MB, 在所有 C++ 提交中击败了90.33%的用户
通过测试用例：103 / 103

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
  // function start.
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    int n = nums.size();
    vector<int> cnt(101, 0);
    vector<int> res(n);

    for (int i = 0; i < n; i++)
      cnt[nums[i]]++;

    for (int i = 1; i <= 100; i++)
      cnt[i] += cnt[i - 1];

    for (int i = 0; i < n; i++)
      res[i] = nums[i] == 0 ? 0 : cnt[nums[i] - 1];

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
