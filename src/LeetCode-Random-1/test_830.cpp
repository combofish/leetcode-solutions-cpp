/**
-- method: for, start_idx, end_idx.

--result:
执行用时：4 ms, 在所有 C++ 提交中击败了55.56%的用户
内存消耗：7.5 MB, 在所有 C++ 提交中击败了5.07%的用户
通过测试用例：202 / 202
 */

#include "combofish_utils.hpp"

class Solution {
public:
  // function start.
  vector<vector<int>> largeGroupPositions(string s) {
    vector<vector<int>> res;

    int s_idx = 0;
    int e_idx = 0;
    char curChar = s[0];

    for (int i = 0; i < s.size(); i++) {

      if (s[i] != curChar) {
        e_idx = i;

        IC(i, s[i], curChar, s_idx, e_idx);

        if (e_idx - s_idx >= 3) {
          vector<int> s = {s_idx, e_idx - 1};
          res.emplace_back(s);
        }

        curChar = s[i];
        s_idx = i;
      }
    }

    e_idx = s.size();
    if (e_idx - s_idx >= 3) {
      vector<int> s = {s_idx, e_idx - 1};
      res.emplace_back(s);
    }

    return res;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  string s = "abcdddeeeeaabbbcd";
  IC(s);

  IC(solution->largeGroupPositions(s));
  return 0;
}
