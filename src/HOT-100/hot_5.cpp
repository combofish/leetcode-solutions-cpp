/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <armadillo>

class Solution {

    // function start.
public:
    // 中心扩展算法
    string longestPalindrome(string s) {
        int n = s.size();
        auto extend = [&s, &n](int i, int j) {
            string res = "";
            while (i >= 0 && j < n && s[i] == s[j]) {
                string tmp = s.substr(i, j - i + 1);
                if (tmp.size() > res.size()) res = tmp;
                i--;
                j++;
            }
            return res;
        };

        string res = "";
        for (int i = 0; i < n; i++) {
            string tmp1 = extend(i, i);
            string tmp2 = extend(i, i+1);
            if (tmp1.size() > res.size()) res = tmp1;
            if (tmp2.size() > res.size()) res = tmp2;
        }

        IC(res);
        return res;
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "babad", rel = "bab";

    IC(s, rel);
    IC(solution->longestPalindrome(s) == rel);
    // code end

    delete solution;
    return 0;
}


