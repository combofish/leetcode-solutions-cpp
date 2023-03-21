/**
执行用时：120 ms, 在所有 C++ 提交中击败了90.27%的用户
内存消耗：56.1 MB, 在所有 C++ 提交中击败了28.76%的用户
通过测试用例：68 / 68
 */

#include "combofish_utils.hpp"

class RecentCounter {
  queue<int> qu;

public:
  RecentCounter() {}

  int ping(int t) {
    qu.push(t);

    while (qu.front() < t - 3000) {
      qu.pop();
    }

    out_qu(qu);
    return qu.size();
  }
};

int main() {

  // code start
  RecentCounter *obj = new RecentCounter();
  // int param_1 = obj->ping(t);

  vec_t nums = {1, 100, 3001, 3002, 7000};
  for (const int &i : nums) {
    IC(i, obj->ping(i));
  }

  return 0;
}
