/**
-- method: for, double pointer, perm[i]=

--result:
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：8.3 MB, 在所有 C++ 提交中击败了85.27%的用户
通过测试用例：95 / 95
 */

#include "combofish_utils.hpp"

vector<int> diStringMatch(string s) {
  int n = s.size();
  int low = 0, high = n;
  vec_t perm(n + 1);

  for (int i = 0; i < n; ++i) {
    perm[i] = s[i] == 'I' ? low++ : high--;
  }

  perm[n] = low;

  return perm;
}

int main() {
  // code start
  string s = "IDID";
  IC(s, diStringMatch(s));

  return 0;
}
