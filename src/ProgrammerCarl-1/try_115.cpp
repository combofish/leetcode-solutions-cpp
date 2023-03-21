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

    int numDistinct(string s, string t) {
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size(), 0));
        for (auto &line: dp) line.front() = 1;

        for (int i = 1; i <= s.size(); i++)
            for (int j = 1; j <= t.size(); j++)
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];

        return dp.back().back();

    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "rabbbit", t = "rabbit";
    int rel = 3;

    IC(s, t, rel);
    IC(solution->numDistinct(s, t) == rel);
    // code end

    delete solution;
    return 0;
}


