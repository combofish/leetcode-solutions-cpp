/**
执行用时：312 ms, 在所有 C++ 提交中击败了7.78%的用户
内存消耗：56.7 MB, 在所有 C++ 提交中击败了10.27%的用户
通过测试用例：68 / 68
 */

#include "combofish_utils.hpp"

class RecentCounter {
  vec_t requests;
  int limit = 3000;

public:
  RecentCounter() {}

  int ping(int t) {
    requests.emplace_back(t);

    int j = std::max(0, t - limit);
    IC(j, t);

    int cnt = 0;
    int i = requests.size() - 1;
    while (i >= 0 && requests[i] >= j) {
      IC(requests[i], j, requests[i] > j);
      ++cnt;
      --i;
    }

    return cnt;
  }
};

int main() {

  // code start
  RecentCounter *obj = new RecentCounter();
  // int param_1 = obj->ping(t);

  vec_t nums = {1, 100, 3001, 3002};
  for (const int &i : nums) {
    IC(i, obj->ping(i));
  }

  return 0;
}
