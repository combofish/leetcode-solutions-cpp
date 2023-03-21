/**
-- method: 二分查找

--result:
执行用时： 8 ms , 在所有 C++ 提交中击败了 99.39% 的用户
内存消耗： 5.8 MB , 在所有 C++ 提交中击败了 81.90% 的用户
通过测试用例： 70 / 70

-- analyse:
Time: O(m logmn)
Space: O(1)

 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <numeric>

class Solution {
public:
  // function start.
  int findKthNumber(int m, int n, int k) {
    int left = 1, right = m * n;

    while (left < right) {
      int x = left + (right - left) / 2;
      int cnt = x / n * n;

      cout << endl;
      IC(left, x, right, cnt);

      for (int i = x / n + 1; i <= m; ++i) {
        cnt += x / i;
        IC(i, x / i);
      }

      IC(cnt, k);

      if (cnt >= k)
        right = x;
      else
        left = x + 1;
    }
    return left;
  }

  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  int m = 3, n = 3, k = 6;
  IC(m, n, k);
  IC(solution->findKthNumber(m, n, k));
  IC(4);

  cout << endl;
  IC();

  int m1 = 2, n1 = 3, k1 = 6;
  IC(m1, n1, k1);
  IC(solution->findKthNumber(m1, n1, k1));
  IC(6);

  return 0;
}
