/**
-- method: record remainder, combination.

-- result:
执行用时： 24 ms , 在所有 C++ 提交中击败了 88.38% 的用户
内存消耗： 27.3 MB , 在所有 C++ 提交中击败了 88.38% 的用户
通过测试用例： 35 / 35
 */

#include "combofish_utils.hpp"

int numPairsDivisibleBy60(vector<int> &time) {
  if (time.size() == 1)
    return 0;

  int seconds[60] = {0};
  for (const int &i : time)
    seconds[i % 60]++;

  int i = 1, ret = 0;
  while (i < 30) {
    ret += seconds[i] * seconds[60 - i];
    ++i;
  }

  auto combination = [](int n) {
    long result = 1;
    result = (long)n * (long)(n - 1) / 2;
    return (int)result;
  };

  // seconds[0]/2 :like 3/2 = 1, wrong.
  // return ret + seconds[0] / 2 * (seconds[0] - 1) +
  //        seconds[30] / 2 * (seconds[30] - 1);

  return ret + combination(seconds[0]) + combination(seconds[30]);
}

int main() {
  // code start
  // vec_t time = {30, 20, 150, 100, 40};
  vec_t time = {60, 60, 60};
  IC(time, numPairsDivisibleBy60(time));

  return 0;
}
