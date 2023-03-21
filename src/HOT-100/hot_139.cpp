/**
-- question: 单词拆分
-- method:
 - [*] 动态规划

--result:

-- analyse:
Time: O(n^3)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        auto wordDictSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        int n = s.size();
        auto dp = vector<bool>(n + 1, false);
        dp.front() = true;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                auto word = s.substr(j, i - j);
                // if (wordDictSet.find(word) != wordDictSet.end() && dp[j]) dp[i] = true;
                if (wordDictSet.count(word) && dp[j]) dp[i] = true;
            }
            IC(dp);
        }

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
    bool rel = true;
    IC(s, wordDict, rel);

    IC(solution->wordBreak(s, wordDict));
    // code end

    return 0;
}
