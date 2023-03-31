/**
-- question: 单词拆分
-- method:
 - [ ] 动态规划

--result:

-- analyse:
Time: O(n^2)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> uet(wordDict.cbegin(), wordDict.cend());

        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp.front() = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
//                auto word = s.substr(j, i - j);
//                IC(word);
//
//                if (uet.count(word) && dp[j]) dp[i] = true;

                if (dp[j] && uet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        IC(dp);
        return dp.back();

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    bool ans = true;
    IC(s, wordDict, ans);

    IC(solution->wordBreak(s, wordDict));

    // code end

    return 0;
}


