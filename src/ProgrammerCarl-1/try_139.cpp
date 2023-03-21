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
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp.front() = true;

        for (int i = 1; i <= s.size(); i++)
            for (int j = 0; j < i; j++) {
                string word = s.substr(j, i - j );
                if (wordSet.find(word) != wordSet.end() && dp[j]) dp[i] = true;
            }

        IC(dp);
        return dp.back();
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    bool rel = true;

    IC(s, wordDict, rel);
    IC(solution->wordBreak(s, wordDict) == rel);

    // code end

    delete solution;
    return 0;
}


