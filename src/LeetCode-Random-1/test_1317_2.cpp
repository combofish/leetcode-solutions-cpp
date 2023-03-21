/**
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了77.98%的用户
通过测试用例：206 / 206
 */

#include "combofish_utils.hpp"
#include <string>

vector<int> getNoZeroIntegers(int n) {

  int i = 1, j = n - 1;
  while ((std::to_string(i) + std::to_string(j)).find('0') != string::npos) {
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
