/**
-- method: for

--result:
执行用时：28 ms, 在所有 C++ 提交中击败了91.94%的用户
内存消耗：25.2 MB, 在所有 C++ 提交中击败了66.93%的用户
通过测试用例：40 / 40
 */

#include "combofish_utils.hpp"
#include <math.h>

class Solution {
public:
  // function start.
  int findPoisonedDuration(vector<int> &timeSeries, int duration) {
    int count = 0;
    int n = timeSeries.size();

    for (int i = 1; i < n; i++) {
      int duc = timeSeries[i] - timeSeries[i - 1];
      if (duc < duration) {
        count += duc;
      } else {
        count += duration;
      }
    }

    return count + duration;
  }
  // function end.
};

int main() {
  Solution *solution = new Solution();

  // code start
  vec_t timeSeries = {1, 4};
  int duration = 2;

  IC(timeSeries, duration);
  IC(solution->findPoisonedDuration(timeSeries, duration));

  return 0;
}
