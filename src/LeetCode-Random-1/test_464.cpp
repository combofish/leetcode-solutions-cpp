/**
-- method: 记忆化搜索 + 状态压缩

--result:
执行用时：892 ms, 在所有 C++ 提交中击败了16.15%的用户
内存消耗：87.4 MB, 在所有 C++ 提交中击败了33.20%的用户
通过测试用例：57 / 57

-- analyse:
Time: O((2^n) * n)
Space: O(2^n)

 */

#include "combofish_utils.hpp"

class Solution {
  unordered_map<int, bool> memo;

  bool dfs(int maxChoosableInteger, int usedNumbers, int desiredTotal,
           int currentTotal) {
    if (!memo.count(usedNumbers)) {
      bool res = false;
      for (int i = 0; i < maxChoosableInteger; i++) {
        IC(i, usedNumbers, usedNumbers >> i, (usedNumbers >> i) & i);

        if (((usedNumbers >> i) & 1) == 0) {
          if (1 + i + currentTotal >= desiredTotal) {
            res = true;
            break;
          }
          if (!dfs(maxChoosableInteger, usedNumbers | (1 << i), desiredTotal,
                   currentTotal + i + 1)) {
            res = true;
            break;
          }
        }
      }
      memo[usedNumbers] = res;
    }

    cout << endl;
    // IC(memo);
    // cout << endl;
    return memo[usedNumbers];
  }

public:
  // function start.
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if ((1 + maxChoosableInteger) * (maxChoosableInteger) / 2 < desiredTotal) {

      return false;
    }
    return dfs(maxChoosableInteger, 0, desiredTotal, 0);
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  int maxChoosableInteger = 10, desiredTotal = 40;
  IC(maxChoosableInteger, desiredTotal);
  IC(solution->canIWin(maxChoosableInteger, desiredTotal));
  IC(false);

  return 0;
}
