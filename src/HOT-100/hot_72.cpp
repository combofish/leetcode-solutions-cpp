/**
-- question: 编辑距离
-- method:
 - [ ] 

--result:

-- analyse:
Time: O(mn)
Space: O(mn)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        auto dp = vector<vector<int>>(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 0; i <= n1; i++) dp[i].front() = i;
        for (int i = 0; i <= n2; i++) dp.front()[i] = i;

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
            IC(dp);
        }

        return dp.back().back();
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string word1 = "horse", word2 = "ros";
    int rel = 3;
    IC(word1, word2, rel);
    IC(solution->minDistance(word1, word2));

    // code end

    return 0;
}
