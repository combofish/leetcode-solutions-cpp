/**
-- question: 正则表达式匹配
-- method:
 - [ ] 动态规划

--result:

-- analyse:
Time: O(mn)
Space: O(mn)
 */

#include "../combofish_utils.hpp"

class Solution {

    // function start.
public:

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        // f[i][j] 表示 s 的前 i 个字符与 p 中的前 j 个字符是否能够匹配。

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp.front().front() = 1;

        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] |= dp[i][j - 2];
                    if (mayMatch(s, p, i, j - 1)) dp[i][j] |= dp[i - 1][j];
                } else {
                    if (mayMatch(s, p, i, j))
                        dp[i][j] |= dp[i - 1][j - 1];
                }
            }
        }
        IC(dp);

        return dp.back().back();


    }

private:

    inline bool mayMatch(const string &s, const string &p, int i, int j) {
        if (i == 0) return false;
        if (p[j - 1] == '.') return true;
        return s[i - 1] == p[j - 1];
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    string s = "abbdbc", p = "ab.d.c";
    bool ans = true;
    IC(s, p, ans);

    IC(solution->isMatch(s, p));

    // code end

    return 0;
}
