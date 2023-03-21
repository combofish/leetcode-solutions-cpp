/**
-- method: while, count,

--result:
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了24.67%的用户
通过测试用例：64 / 64

 */

#include "combofish_utils.hpp"

int numWaterBottles(int numBottles, int numExchange) {
  IC(numBottles, numExchange);

  int count = numBottles;
  int left = numBottles;

  while (left >= numExchange) {
    int yu = left % numExchange;
    left = left / numExchange;

    count += left;
    left += yu;
    IC(left, yu, count);
  }

  return count;
}

int main() {
  // code start
  mat_t mat = {{9, 3, 13}, {15, 4, 19}, {5, 5, 6}, {2, 3, 2}};

  for (auto &v : mat)
    IC(numWaterBottles(v[0], v[1]) == v[2]);
  return 0;
}
