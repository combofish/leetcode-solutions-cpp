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

    // function start.
public:
    int countSubstrings(string s) {

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), 0));
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--)
            for (int j = i; j < s.size(); j++)
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        ++result;
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) {
                        ++result;
                        dp[i][j] = true;
                    }
                }

        return result;

    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "aaa";
    int rel = 6;
    vector<string> rel_s = {"a", "a", "a", "aa", "aa", "aaa"};

    IC(s, rel, rel_s);
    IC(solution->countSubstrings(s) == rel);

    // code end

    delete solution;
    return 0;
}


