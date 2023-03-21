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
    int longestCommonSubsequence(string text1, string text2) {

        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); i++)
            for (int j = 1; j <= text2.size(); j++)
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);

        return dp.back().back();
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string text1 = "abcde";
    string text2 = "ace";
    int rel = 3;

    IC(text1, text2, rel);
    IC(solution->longestCommonSubsequence(text1, text2) == rel);
    // code end

    delete solution;
    return 0;
}


