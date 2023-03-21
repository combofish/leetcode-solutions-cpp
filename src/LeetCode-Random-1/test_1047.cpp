/**

 */

#include "combofish_utils.hpp"
#include <string>

string removeDuplicates(string s) {

  bool need_precedd = true;
  int i = 0;

  while (need_precedd) {
    // IC();
    need_precedd = false;

    IC(s, s.size(), s.size() - 1, need_precedd);

    if (s.size() <= 1)
      break;

    i = std::max(0, i - 1);

    IC(i);

    for (; i < s.size() - 1; ++i) {
      if (s[i] == s[i + 1]) {
        s.erase(s.begin() + i, s.begin() + i + 2);
        IC(s);

        need_precedd = true;
        break;
      }
    }
  }

  return s;
}

int main() {
  // code start

  string s = "dabbaca"; // Res: "dca"
  IC(s.size());
  IC(removeDuplicates(IC(s)));

  return 0;
}
