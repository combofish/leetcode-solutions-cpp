/**
执行用时：124 ms, 在所有 C++ 提交中击败了83.78%的用户
内存消耗：56.7 MB, 在所有 C++ 提交中击败了9.73%的用户
通过测试用例：68 / 68
 */

#include "combofish_utils.hpp"

class RecentCounter {
  vec_t requests;
  int limit = 3000;
  int left_idx = 0;

public:
  RecentCounter() {}

  int ping(int t) {
    requests.emplace_back(t);

    while (requests[left_idx] < t - limit) {
      left_idx++;
    }

    IC(left_idx, t, requests);

    return requests.size() - left_idx;
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
