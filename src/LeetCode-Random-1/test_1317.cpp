/**
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：6.2 MB, 在所有 C++ 提交中击败了32.11%的用户
通过测试用例：206 / 206
 */

#include "combofish_utils.hpp"
#include <string>

vector<int> getNoZeroIntegers(int n) {
  auto noZero = [](int i) {
    string s = std::to_string(i);
    return std::all_of(s.begin(), s.end(),
                       [](const char &c) { return c >= '1' && c <= '9'; });
  };

  int i = 1, j = n - 1;
  IC(i, noZero(i), j, noZero(j));

  while (!(noZero(i) && noZero(j))) {
    ++i;
    --j;
  }

  return {i, j};
}

int main() {
  // code start
  int n = 1010;
  IC(n);
  IC(getNoZeroIntegers(n));

  return 0;
}
