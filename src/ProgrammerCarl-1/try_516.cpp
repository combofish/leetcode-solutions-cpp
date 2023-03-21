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
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
        for (int i = s.size() - 1; i >= 0; i--)
            for (int j = i + 1; j < s.size(); j++)
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);

        return dp.front().back();

    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "bbbab";
    int rel = 4;
    IC(s, rel);
    IC(solution->longestPalindromeSubseq(s) == rel);


    // code end

    delete solution;
    return 0;
}


