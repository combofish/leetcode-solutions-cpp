/**
-- method: umap, cmp

--result:
执行用时： 4 ms , 在所有 C++ 提交中击败了 85.44% 的用户
内存消耗： 9.3 MB , 在所有 C++ 提交中击败了 54.88% 的用户
通过测试用例： 120 / 120

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"

class Solution {
  // 根据给定的字母表来比较两个字符串的大小
  bool cmpStr(const string &s1, const string &s2,
              unordered_map<char, int> &umap) {
    int n = std::min(s1.size(), s2.size());

    for (int i = 0; i < n; i++) {
      if (umap[s2[i]] > umap[s1[i]]) {
        return true;
      } else if (umap[s2[i]] < umap[s1[i]]) {
        return false;
      }
    }

    return s1.size() <=
           s2.size(); // 当两个字符串相同长度部分字母相同时，长度大的字符串大
  }

public:
  // function start.
  inline bool isAlienSorted(vector<string> &words, string order) {
    unordered_map<char, int> umap; // 存储字母对应的排序位置
    for (int i = 0; i < 26; ++i)   // 初始化哈希表
      umap[order[i]] = i;

    IC(umap);

    for (int i = 0, n = words.size(); i < n - 1; i++)
      if (!cmpStr(words[i], words[i + 1], umap))
        return false; // 不满足，提前结束

    return true; // 所有单词均满足升序排列
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  vector<string> words = {"hello", "leetcode"};
  string order = "hlabcdefgijkmnopqrstuvwxyz";
  IC(words, order);
  IC(solution->isAlienSorted(words, order));
  IC(1);
  return 0;
}
