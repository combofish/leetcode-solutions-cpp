/**
-- method: for, double pointer, emplace_back

--result:
执行用时：4 ms, 在所有 C++ 提交中击败了88.53%的用户
内存消耗：8.9 MB, 在所有 C++ 提交中击败了22.09%的用户
通过测试用例：95 / 95
 */

#include "combofish_utils.hpp"

vector<int> diStringMatch(string s) {
  int n = s.size();
  int low = 0, high = n;
  vec_t perm;

  for (const char &c : s) {
    perm.emplace_back(c == 'I' ? low++ : high--);
  }

  perm.emplace_back(low);
  return perm;
}

int main() {
  // code start
  string s = "IDID";
  IC(s, diStringMatch(s));

  return 0;
}
