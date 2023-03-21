/**
-- method: 二分查找

--result:
执行用时：32 ms, 在所有 C++ 提交中击败了81.76%的用户
内存消耗：18.4 MB, 在所有 C++ 提交中击败了27.02%的用户
通过测试用例：121 / 121

-- analyse:
Time: O(nlogm) :其中 nn 是数组 piles 的长度，mm 是数组 piles 中的最大值
Space: O(1)

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
  long getTime(vec_t &piles, int speed) {
    long ret = 0;
    for (int pile : piles) {
      int curTime = (pile + speed - 1) / speed;
      ret += curTime;
    }
    return ret;
  }

public:
  // function start.
  int minEatingSpeed(vector<int> &piles, int h) {
    int low = 1;
    int high = *std::max_element(piles.begin(), piles.end());
    int k = high;
    while (low < high) {
      int speed = (high - low) / 2 + low;
      long time = getTime(piles, speed);
      if (time <= h) {
        k = speed;
        high = speed;
      } else {
        low = speed + 1;
      }
    }
    return k;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  vec_t piles = {3, 6, 7, 11};
  int h = 8;
  int ant = 4;
  IC(piles, h, ant);
  IC(solution->minEatingSpeed(piles, h));
  return 0;
}
