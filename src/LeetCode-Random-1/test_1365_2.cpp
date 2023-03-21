/**
-- method: sort

--result:
执行用时：4 ms, 在所有 C++ 提交中击败了91.98%的用户
内存消耗：10.1 MB, 在所有 C++ 提交中击败了17.59%的用户
通过测试用例：103 / 103
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
  // function start.
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    int n = nums.size();
    vector<pair<int, int>> data;
    for (int i = 0; i < n; i++)
      data.emplace_back(nums[i], i);

    std::sort(data.begin(), data.end());

    IC(data);

    vec_t res(n);
    int prev = -1;

    for (int i = 0; i < n; i++) {
      if (prev == -1 || data[i].first != data[i - 1].first) {
        prev = i;
      }

      res[data[i].second] = prev;
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
