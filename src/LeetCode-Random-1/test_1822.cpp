/**
-- method: count neg num

--result:
执行用时：4 ms, 在所有 C++ 提交中击败了86.87%的用户
内存消耗：10 MB, 在所有 C++ 提交中击败了9.50%的用户
通过测试用例：76 / 76
 */

#include "combofish_utils.hpp"

int arraySign(vector<int> &nums) {
  int neg = 0;
  for (const int &i : nums) {
    if (i == 0)
      return 0;
    else if (i < 0)
      neg++;
  }

  IC(neg);
  return neg % 2 == 0 ? 1 : -1;
}

int main() {
  // code start
  vec_t nums = {-1, -2, -3, -4, 3, 2, 1};
  IC(nums);

  IC(arraySign(nums));

  return 0;
}
