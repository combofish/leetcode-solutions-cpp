/**
-- method: vec_rec

--result:
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了86.24%的用户
通过测试用例：73 / 73

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <string>

class Solution {
public:
  // function start.
  string validIPAddress(string queryIP) {
    vector<string> vec;
    int n = queryIP.size();
    if (n > 39)
      return "Neither";
    int j = 0;
    int i = 0;
    for (; i < n; i++) {
      if (queryIP[i] == '.' || queryIP[i] == ':') {
        vec.emplace_back(queryIP.substr(j, i - j));
        j = i + 1;
      }
    }
    vec.emplace_back(queryIP.substr(j, i - j));

    IC(vec);

    if (vec.size() == 4) {

      for (auto &s : vec) {
        // 前导零判断
        if (s[0] == '0' && s.size() > 1) {
          return "Neither";
        }

        if (s.size() == 0 || s.size() > 3)
          return "Neither";

        for (int i = 0; i < s.size(); i++) {
          if (s[i] < '0' || s[i] > '9') {
            return "Neither";
          }
        }
        int a = std::stoi(s);
        if (a < 0 || a > 255) {
          return "Neither";
        }
        IC(a);
      }

      return "IPv4";
    } else if (vec.size() == 8) {
      for (auto &s : vec) {
        IC(s);
        int s_n = s.length();
        if (s_n < 1 || s_n > 4) {
          return "Neither";
        }
        for (int i = 0; i < s_n; ++i) {
          char a = s[i];
          if (!((a >= '0' && a <= '9') || (a >= 'a' && a <= 'f') ||
                (a >= 'A' && a <= 'F'))) {
            return "Neither";
          }
        }
      }

      return "IPv6";
    }
    return "Neither";
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  string queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334";
  string queryIP2 = "172.16.254.1";
  string queryIP3 = "256.256.256.256";

  IC(queryIP, queryIP2, queryIP3);
  IC(solution->validIPAddress(queryIP));
  IC(6);
  IC(solution->validIPAddress(queryIP2));
  IC(4);
  IC(solution->validIPAddress(queryIP3));
  IC(0);

  string queryIP4 = "1e1.4.5.6";
  IC(queryIP4);
  IC(solution->validIPAddress(queryIP4));
  IC(0);

  string queryIP5 = "1.0.1.";
  IC(queryIP5);
  IC(solution->validIPAddress(queryIP5));
  IC(0);
  return 0;
}
