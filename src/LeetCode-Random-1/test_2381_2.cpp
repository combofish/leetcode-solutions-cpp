/**
-- method: umap<char,int> rec

--result:
执行用时：28 ms, 在所有 C++ 提交中击败了75.72%的用户
内存消耗：10.5 MB, 在所有 C++ 提交中击败了62.65%的用户
通过测试用例：105 / 105
 */

#include "combofish_utils.hpp"
#include <utility>

class Solution {
public:
  // function start.
  char firstUniqChar(string s) {
    unordered_map<char, int> umap;
    for (auto &c : s)
      umap[c]++;

    for (const char &c : s) {
      if (umap[c] == 1)
        return c;
    }

    return ' ';
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start

  string s = "abaccdeff";

  IC(s);
  IC(solution->firstUniqChar(s));
  return 0;
}
