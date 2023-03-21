/**
-- method: for, i, j

--result:
执行用时：96 ms, 在所有 C++ 提交中击败了71.63%的用户
内存消耗：58 MB, 在所有 C++ 提交中击败了49.30%的用户
通过测试用例：43 / 43

-- analyse:
Time: O(n)
Space: O(1)

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
  unordered_map<string, vector<int>> umap;

public:
  // function start.
  int findClosest(vector<string> &words, string word1, string word2) {
    int n = words.size();
    int ret = n;
    int i = -1, j = -1;
    for (int k = 0; k < n; k++) {
      if (words[k] == word1)
        i = k;
      else if (words[k] == word2)
        j = k;
      else
        continue;

      if (i >= 0 && j >= 0) {
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
