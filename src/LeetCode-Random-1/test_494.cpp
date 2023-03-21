/**
-- method: dfs

--result:
执行用时：1372 ms, 在所有 C++ 提交中击败了5.80%的用户
内存消耗：8.7 MB, 在所有 C++ 提交中击败了83.52%的用户
通过测试用例：139 / 139
 */

#include "combofish_utils.hpp"

class Solution {
  void dfs(vector<int> &nums, int &target, int idx, int count, int &cnt) {
    if (idx == nums.size()) {
      if (count == target)
        cnt++;
      return;
    }

    dfs(nums, target, idx + 1, count + nums[idx], cnt);
    dfs(nums, target, idx + 1, count - nums[idx], cnt);
  }

public:
  // function start.
  int findTargetSumWays(vector<int> &nums, int target) {
    int cnt = 0;
    dfs(nums, target, 0, 0, cnt);
    return cnt;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  //   vec_t nums = {1, 1, 1, 1, 1};
  // int target = 3;
  vec_t nums = {1};
  int target = 1;

  IC(nums, target);
  IC(solution->findTargetSumWays(nums, target));
  return 0;
}
