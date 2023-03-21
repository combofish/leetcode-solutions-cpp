/**
-- question:
-- method:
 - [ ] 中心扩展算法

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    string longestPalindrome(string s) {

        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++) {
            auto [lk1, rk1] = isPalindrome(s, i, i);
            auto [lk2, rk2] = isPalindrome(s, i, i + 1);

            if (rk1 - lk1 > end - start) {
                start = lk1;
                end = rk1;
            }
            if (rk2 - lk2 > end - start) {
                start = lk2;
                end = rk2;
            }

            auto s1 = s.substr(lk1, rk1 - lk1 + 1);
            auto s2 = s.substr(lk2, rk2 - lk2 + 1);
            IC(s1, s2);
        }
        return s.substr(start, end - start + 1);
    }

private:
    pair<int, int> isPalindrome(const string &s, int lk, int rk) {
        while (lk >= 0 && rk < s.size() && s[lk] == s[rk]) {
            lk--;
            rk++;
        }
        return {lk + 1, rk - 1};
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "babad";
    string result = "bab";

    IC(s, result);

    IC(solution->longestPalindrome(s));

    // code end

    return 0;
}
