/**
-- method: umap<char,pair<int, int>>, rec.

--result:
执行用时：28 ms, 在所有 C++ 提交中击败了75.72%的用户
内存消耗：10.6 MB, 在所有 C++ 提交中击败了8.68%的用户
通过测试用例：105 / 105
 */

#include "combofish_utils.hpp"
#include <utility>

class Solution {
public:
  // function start.
  char firstUniqChar(string s) {
    unordered_map<char, pair<int, int>> umap;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (umap.find(c) == umap.end()) {
        umap[c] = std::make_pair(i, 1);
      } else {
        umap[c].second++;
      }
    }

    char ret = ' ';
    int idx = s.size();

    for (auto &u : umap) {
      if (u.second.second == 1 && u.second.first < idx) {
        ret = u.first;
        idx = std::min(idx, u.second.first);
      }
    }

    return ret;
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
