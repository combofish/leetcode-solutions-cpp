/**
-- method: 数学推理

--result:
执行用时：4 ms, 在所有 C++ 提交中击败了68.54%的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了64.33%的用户
通过测试用例：170 / 170

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"

class Solution {
  bool isKConsecutive(int n, int k) {
    if (k % 2 == 1)
      return n % k == 0;
    else
      return n % k != 0 && 2 * n % k == 0;
  }

public:
  // function start.
  int consecutiveNumbersSum(int n) {
    int ans = 0;
    int bound = 2 * n;
    for (int k = 1; k * (k + 1) <= bound; k++) {
      if (isKConsecutive(n, k))
        ++ans;
    }

    return ans;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  int n = 15;
  IC(n);
  IC(solution->consecutiveNumbersSum(n));

  mat_t ret = {{15}, {8, 7}, {4, 5, 6}, {1, 2, 3, 4}};
  IC(ret, ret.size());
  return 0;
}
