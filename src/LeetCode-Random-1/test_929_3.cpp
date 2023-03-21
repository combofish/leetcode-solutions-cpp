/**
-- method: uset, for, substr

--result:

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

    for (auto &email : emails) {
      string s = "";
      int at_idx = email.find('@');
      for (auto &c : email.substr(0, at_idx)) {
        if (c == '+')
          break;
        if (c != '.')
          s.push_back(c);
      }

      uset.insert(s + email.substr(at_idx));
    }

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
