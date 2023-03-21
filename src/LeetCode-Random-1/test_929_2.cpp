/**
-- method: uset, for, substr

--result:
执行用时：16 ms, 在所有 C++ 提交中击败了95.77%的用户
内存消耗：13.3 MB, 在所有 C++ 提交中击败了78.11%的用户
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
      for (int i = 0; i < at_idx; i++) {
        if (email[i] == '+')
          break;
        if (email[i] != '.')
          s.push_back(email[i]);
      }

      uset.insert(s + email.substr(at_idx));
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
