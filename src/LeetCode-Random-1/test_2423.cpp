/**
-- method: while, double pointer

--result:
执行用时：4 ms, 在所有 C++ 提交中击败了86.35%的用户
内存消耗：7.1 MB, 在所有 C++ 提交中击败了76.58%的用户
通过测试用例：480 / 480

 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <cctype>
#include <cmath>

bool isPalindrome(string s) {
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);

  int n = s.size();
  int i = 0, j = n - 1;
  while (i < j) {
    if (!std::isalnum(s[i])) {
      ++i;
    } else if (!std::isalnum(s[j])) {
      j--;
    } else {

      IC(i, j, s[i], s[j]);

      if (s[i] == s[j]) {
        ++i;
        --j;
      } else {
        return false;
      }
    }
  }

  return true;
}

int main() {
  // code start
  string s = "A man, a plan, a canal: Panama";

  IC(s, isPalindrome(s));

  return 0;
}
