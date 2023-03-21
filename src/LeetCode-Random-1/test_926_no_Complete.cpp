/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
  // function start.
  int minFlipsMonoIncr(string s) {
    int zn = 0, on = 0;
    int i = 0;
    int n = s.size();
    while (i < n && s[i] == '0')
      i++;

    if (i == n)
      return 0;

    for (int j = i; j < n; j++) {
      if (s[j] == '0')
        zn++;
      else
        on++;
    }

    return std::min(zn, on);
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  string res = "00011000";
  IC(res);
  IC(solution->minFlipsMonoIncr(res));
  IC(2);

  out_line();
  string res2 = "00110";
  IC(res2);
  IC(solution->minFlipsMonoIncr(res2));
  IC(1);

  out_line();
  string res3 = "0101100011";
  IC(res3);
  IC(solution->minFlipsMonoIncr(res3));
  IC(3);
  // code end

  delete solution;
  return 0;
}
