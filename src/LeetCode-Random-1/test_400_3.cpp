/**
-- method: while, add, pow

--result:
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了13.62%的用户
通过测试用例：71 / 71
 */

#include "combofish_utils.hpp"
#include <string>

class Solution {
public:
  // function start.
  int findNthDigit(int n) {
    if (n >= 1 && n <= 9)
      return n;

    long e = 9;
    long s = 1;
    int bit = 1;

    while (n > e * bit) {
      IC(n, e, s, bit);

      n -= e * bit;
      bit++;
      e *= 10;
      s *= 10;
    }

    //    int add = (n - 1) / bit;
    long add = (n - bit + 1) / bit;
    int idx = n % bit;
    long add_n = add + s;
    IC(add, idx, add_n, add_n / (int)std::pow(10, bit - idx));
    //    IC(s, e, n, bit, add, add_n, idx);

    // int ret = 0;
    // if (idx == -1) {
    //   ret = std::to_string(add_n).back() - '0';
    // } else {
    //   ret = std::to_string(add_n)[idx] - '0';
    // }

    string str = std::to_string(add_n);

    if (idx == 0) {
      return add_n % 10;
    } else {
      //      return *(str.begin() + idx - 1) - '0';
      return (add_n / (int)std::pow(10, bit - idx)) % 10;
    }

    //    return str[str.size() - idx - 1] - '0';
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  int n = 1002;
  // 1000 -> 3;
  // 1001 -> 7;
  // 1002 -> 0;

  // int s = 100;
  // int e = 103; // 5, 5, 5, 6

  // int s = 1000;
  // int e = 1003;

  // int s = 1;
  // int e = 12;

  int s = 1000000000;
  int e = 1000000000; // 1
  IC(n);

  for (int i = s; i <= e; ++i) {
    IC(i, solution->findNthDigit(i));
    cout << endl;
  }

  return 0;
}
