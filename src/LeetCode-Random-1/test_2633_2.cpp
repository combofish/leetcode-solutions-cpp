/**
-- method: umap record

--result:
执行用时：180 ms, 在所有 C++ 提交中击败了20.93%的用户
内存消耗：88.1 MB, 在所有 C++ 提交中击败了13.02%的用户
通过测试用例：43 / 43

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
  unordered_map<string, vector<int>> umap;

public:
  // function start.
  int findClosest(vector<string> &words, string word1, string word2) {
    int n = words.size();

    if (umap.empty()) {
      for (int i = 0; i < n; i++)
        umap[words[i]].emplace_back(i);
    }

    IC(umap);

    int ret = n;
    for (auto &i : umap[word1]) {
      for (auto &j : umap[word2]) {
        ret = std::min(std::abs(i - j), ret);
      }
    }

    return ret;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();
  vector<string> words = {"I", "am",         "a",  "student", "from",
                          "a", "university", "in", "a",       "city"};
  string word1 = "a", word2 = "student";

  // code start
  IC(words, word1, word2);
  IC(solution->findClosest(words, word1, word2));
  IC(1);

  return 0;
}
