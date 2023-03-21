/**
-- method: uset, for, for

--result:
执行用时：332 ms, 在所有 C++ 提交中击败了12.49%的用户
内存消耗：44.6 MB, 在所有 C++ 提交中击败了7.44%的用户
通过测试用例：167 / 167
 */

#include "combofish_utils.hpp"
#include <algorithm>

bool isDifferent(const string &s, const unordered_set<char> &uset) {
  for (const char &c : s) {
    if (uset.find(c) != uset.end())
      return false;
  }

  return true;
}

int maxProduct(vector<string> &words) {
  int ret = 0;
  int n = words.size();

  for (int i = 0; i < n - 1; ++i) {
    unordered_set<char> uset;
    int ws = words[i].size();

    for (const char &c : words[i])
      uset.emplace(c);

    for (int j = i + 1; j < n; ++j) {
      if (isDifferent(words[j], uset)) {
        int res = ws * words[j].size();
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
