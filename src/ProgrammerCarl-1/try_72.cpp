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
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j < word2.size(); j++) dp[0][j] = j;
        for (int i = 1; i < word1.size() + 1; i++)
            for (int j = 1; j < word2.size() + 1; j++)
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;

        return dp.back().back();
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string word1 = "intention", word2 = "execution";
    int rel = 5;
    IC(word1, word2, rel);
    IC(solution->minDistance(word1, word2) == rel);

    // code end

    delete solution;
    return 0;
}


