/**
-- method: while

--result:
执行用时：68 ms, 在所有 C++ 提交中击败了12.19%的用户
内存消耗：56.2 MB, 在所有 C++ 提交中击败了46.60%的用户
通过测试用例：68 / 68
 */

#include "combofish_utils.hpp"

class Solution {
public:
  // function start.
  bool kLengthApart(vector<int> &nums, int k) {
    int i = 0;
    int n = nums.size();
    while (i < n && nums[i] != 1)
      ++i;

    int cnt = 0;
    i++;
    while (i < n) {
      if (nums[i] == 0) {
        cnt++;
      } else {
        if (cnt < k)
          return false;
        cnt = 0;
      }

      i++;
    }

    return true;
  }

  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  //  vec_t nums = {1, 0, 0, 0, 1, 0, 0, 1};
  vec_t nums = {0, 0, 0, 0};
  int k = 2;
  IC(nums, k);

  IC(solution->kLengthApart(nums, k));
  return 0;
}
