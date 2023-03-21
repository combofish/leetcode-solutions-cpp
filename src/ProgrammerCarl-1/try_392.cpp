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
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++)
            for (int j = 1; j <= t.size(); j++)
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = dp[i][j - 1];

        return dp.back().back() == s.size();

    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "abc", t = "ahbgdc";
    int rel = true;
    IC(s, t, rel);
    IC(solution->isSubsequence(s, t) == rel);


    // code end

    delete solution;
    return 0;
}


