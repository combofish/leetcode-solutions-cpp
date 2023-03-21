/**
-- method: bit operator

--result:
执行用时：32 ms, 在所有 C++ 提交中击败了93.09%的用户
内存消耗：16.2 MB, 在所有 C++ 提交中击败了31.78%的用户
通过测试用例：167 / 167
 */

#include "combofish_utils.hpp"
#include <algorithm>

int maxProduct(vector<string> &words) {
  int n = words.size();
  vec_t masks(n);

  for (int i = 0; i < n; ++i) {
    string word = words[i];
    int ws = word.size();
    for (int j = 0; j < ws; ++j) {
      masks[i] |= 1 << (word[j] - 'a');

      IC(word[j] - 'a', masks[i]);
    }
  }

  IC(masks);

  int ret = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if ((masks[i] & masks[j]) == 0) {
        int res = words[i].size() * words[j].size();
        ret = std::max(ret, res);
      }
    }
  }
  return ret;
}

int main() {
  // code start

  vector<string> words = {"eae", "ea", "aaf", "bda",   "fcf",
                          "dc",  "ac", "ce",  "cefde", "dabae"};
  //{"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
  //{"abcw", "baz", "foo", "bar", "fxyz", "abcdef"};

  IC(maxProduct(words));

  return 0;
}
