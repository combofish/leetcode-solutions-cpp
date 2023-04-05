/**
-- question: 编辑距离
-- method:
 - [-] 动态规划

--result:

-- analyse:
Time: O(mn) ： m 为 word1 的长度， n 为 word2 的长度
Space: O(mn)
 */

#include "../combofish_utils.hpp"

/**
用 D[i][j] 表示 A 的前 i 个字母和 B 的前 j 个字母之间的编辑距离。
 */

class Solution {

    // function start.
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        if (n * m == 0)return n + m;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 0; i < n + 1; i++) dp[i][0] = i;
        for (int i = 0; i < m + 1; i++) dp[0][i] = i;

        IC(dp);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                auto left = dp[i - 1][j] + 1;
                auto down = dp[i][j - 1] + 1;
                auto left_down = dp[i - 1][j - 1];

                if (word1[i - 1] != word2[j - 1]) left_down += 1;

                dp[i][j] = std::min({left_down, down, left});
            }
        }

        IC(dp);

        return dp.back().back();

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    string word1 = "horse", word2 = "ros";
    int ans = 3;

    IC(word1, word2);
    IC(ans);
    IC(solution->minDistance(word1, word2));

    // code end

    return 0;
}
