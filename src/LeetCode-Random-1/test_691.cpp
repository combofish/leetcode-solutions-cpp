/**
-- method: 记忆化搜索 + 状态压缩

--result:
执行用时：928 ms, 在所有 C++ 提交中击败了10.47%的用户
内存消耗：363.5 MB, 在所有 C++ 提交中击败了26.02%的用户
通过测试用例：101 / 101
 */

#include "combofish_utils.hpp"

class Solution {
public:
  // function start.

  int minStickers(vector<string> &stickers, string target) {
    int n = target.size();
    vector<int> dp(1 << n, -1);
    dp[0] = 0;
    std::function<int(int)> helper = [&](int mask) {
      if (dp[mask] != -1) {
        return dp[mask];
      }
      dp[mask] = n + 1;
      for (auto &sticker : stickers) {
        int left = mask;
        vector<int> cnt(26);
        for (char &c : sticker) {
          ++cnt[c - 'a'];
        }
        for (int i = 0; i < n; i++) {
          if ((mask >> i & 1) && cnt[target[i] - 'a'] > 0) {
            cnt[target[i] - 'a']--;
            left ^= 1 << i;
          }
        }
        if (left < mask) {
          dp[mask] = std::min(dp[mask], helper(left) + 1);
        }
      }
      return dp[mask];
    };
    int ret = helper((1 << n) - 1);
    return ret > n ? -1 : ret;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  vector<string> stickers = {"with", "example", "science"};
  string target = "thehat";

  IC(stickers, target);
  IC(solution->minStickers(stickers, target));
  IC(solution->_minStickers(stickers, target));
  IC(3);

  return 0;
}
