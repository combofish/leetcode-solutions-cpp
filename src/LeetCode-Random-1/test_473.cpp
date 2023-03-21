/**
-- method: 回溯

--result:
执行用时：236 ms, 在所有 C++ 提交中击败了21.11%的用户
内存消耗：9.6 MB, 在所有 C++ 提交中击败了55.09%的用户
通过测试用例：185 / 185

-- analyse:
Time: O(n^4)
Space: O(n)

 */

#include "combofish_utils.hpp"
#include <functional>

class Solution {
  bool dfs(int idx, vec_t &matchsticks, vec_t &edge, int len) {
    if (idx == matchsticks.size())
      return true;

    for (int i = 0; i < 4; i++) {
      edge[i] += matchsticks[idx];
      if (edge[i] <= len && dfs(idx + 1, matchsticks, edge, len)) {
        return true;
      }
      edge[i] -= matchsticks[idx];
    }

    return false;
  }

public:
  // function start.
  bool makesquare(vector<int> &matchsticks) {
    int totalsum = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (totalsum % 4 != 0)
      return false;

    std::sort(matchsticks.begin(), matchsticks.end(), std::greater<int>());

    vec_t edge(4);
    return dfs(0, matchsticks, edge, totalsum / 4);
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  vec_t matchsticks = {1, 1, 2, 2, 2};
  vec_t matchsticks1 = {3, 3, 3, 3, 4};

  IC(matchsticks, matchsticks1);
  IC(solution->makesquare(matchsticks));
  IC(1);
  IC(solution->makesquare(matchsticks1));
  IC(0);
  return 0;
}
