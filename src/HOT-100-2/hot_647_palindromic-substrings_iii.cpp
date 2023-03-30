/**
-- question: 回文子串
-- method:
 - [ ] 中心拓展
 - [ ] Manacher 算法
 - [-] DP

--result:

-- analyse:
Time: O(n^2)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0;

        // dp[i][j] 表示[i,j]之间的字符串是回文字符串
        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j <= i + 1) dp[i][j] = 1;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
                ans += dp[i][j];
            }

        IC(dp);
        return ans;
    }

private:


    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "abc";
    int ans = 3;
    IC(s, ans);

    IC(solution->countSubstrings(s));
    // code end

    return 0;
}


