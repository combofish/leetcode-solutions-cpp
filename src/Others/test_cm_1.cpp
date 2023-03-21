/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"

class Solution {
public:
  // function start.
  float positive_sum(int N) {
    float ret = 0;
    for (int i = 2; i <= N; ++i)
      ret += 1 / (std::pow(i, 2) - 1);

    return ret;
  }

  float reverse_sum(int N) {
    float ret = 0;
    for (int i = N; i >= 2; --i)
      ret += 1 / (std::pow(i, 2) - 1);

    return ret;
  }

  float sn_exact(int N) { return 0.5 * (3. / 2 - 1. / N - 1. / (N + 1)); }

  void test() {
    int n = 10;
    for (int i = 1; i <= 3; ++i) {
      int N = std::pow(n, 2 * i);
      IC(N, positive_sum(N), reverse_sum(N), sn_exact(N));
    }
  }

  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  int N = 100;
  IC(N, solution->positive_sum(N));
  IC(N, solution->reverse_sum(N));

  IC();
  solution->test();

  return 0;
}
