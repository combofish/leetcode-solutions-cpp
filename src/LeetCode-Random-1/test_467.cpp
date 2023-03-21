/**
-- method: 动态规划

--result:
执行用时：4 ms, 在所有 C++ 提交中击败了91.65%的用户
内存消耗：7.1 MB, 在所有 C++ 提交中击败了70.45%的用户
通过测试用例：81 / 81

-- analyse:
Time: O(n)
Space: O(|Σ|) = O(26)

 */

#include "combofish_utils.hpp"
#include <numeric>

class Solution {
public:
  // function start.
  int findSubstringInWraproundString(string p) {
    vec_t dp(26);
    int k = 0;
    for (int i = 0; i < p.length(); ++i) {
      if (i && (p[i] - p[i - 1] + 26) % 26 == 1) {
        IC(i, p[i], p[i - 1], p[i] - p[i - 1]);
        ++k;
      } else {
        k = 1;
      }

      dp[p[i] - 'a'] = std::max(dp[p[i] - 'a'], k);
    }

    return std::accumulate(dp.begin(), dp.end(), 0);
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  string p = "zab";
  IC(solution->findSubstringInWraproundString(p));

  vector<string> res = {"z", "a", "b", "za", "ab", "zab"};
  IC(res, res.size());
  return 0;
}
