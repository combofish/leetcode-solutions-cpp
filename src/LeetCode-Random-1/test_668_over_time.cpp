/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <numeric>

class Solution {
public:
  // function start.
  int findKthNumber(int m, int n, int k) {
    vec_t rec;

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        rec.emplace_back(i * j);
      }
    }

    IC(rec);
    std::sort(rec.begin(), rec.end());
    IC(rec);

    return rec[k - 1];
  }

  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  int m = 3, n = 3, k = 5;
  IC(m, n, k);
  IC(solution->findKthNumber(m, n, k));
  IC(3);

  int m1 = 2, n1 = 3, k1 = 6;
  IC(m1, n1, k1);
  IC(solution->findKthNumber(m1, n1, k1));
  IC(6);

  return 0;
}
