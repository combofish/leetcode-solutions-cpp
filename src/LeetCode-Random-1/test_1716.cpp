/**
-- method: for, add, week+7

--result:
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了52.29%的用户
通过测试用例：106 / 106

 */

#include "combofish_utils.hpp"

class Solution {
public:
  // function start.
  int totalMoney(int n) {
    int weeks = n / 7;
    int days = n % 7;

    IC(weeks, days);

    int sum = 0;

    for (int i = 1; i <= weeks; i++) {
      int this_week = 28 + 7 * (i - 1);
      IC(this_week);
      sum += this_week;
    }

    for (int i = 0; i < days; i++) {
      sum += weeks + 1 + i;
    }

    return sum;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  int n = 10;
  IC(n);
  IC(solution->totalMoney(n));
  return 0;
}
