/**
-- method: uset, for

--result:
执行用时：20 ms, 在所有 C++ 提交中击败了83.33%的用户
内存消耗：13.2 MB, 在所有 C++ 提交中击败了84.58%的用户
通过测试用例：185 / 185

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"

class Solution {
public:
  // function start.
  int numUniqueEmails(vector<string> &emails) {
    unordered_set<string> uset;

    std::for_each(emails.begin(), emails.end(), [&uset](const string &email) {
      string s = "";
      int at_idx = email.find('@');
      for (int i = 0; i < email.size(); i++) {
        if (i < at_idx) {
          if (email[i] == '.')
            continue;

          if (email[i] == '+') {
            i = at_idx;
          }
        }
        s.push_back(email[i]);
      }
      IC(s);

      uset.insert(s);
    });

    IC(uset);
    return uset.size();
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  vector<string> emails = {"test.email+alex@leetcode.com",
                           "test.e.mail+bob.cathy@leetcode.com",
                           "testemail+david@lee.tcode.com",
                           "a@leetcode.com",
                           "b@leetcode.com",
                           "c@leetcode.com"};
  IC(emails);
  IC(solution->numUniqueEmails(emails));
  IC(5);

  return 0;
}
