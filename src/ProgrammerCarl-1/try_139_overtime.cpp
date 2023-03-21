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
private:
    bool result;

    void backtracking(string s, vector<string> &wordDict, int startIndex, string tmp) {
        // cout << s.size() << " " << startIndex << " " << tmp << " " << (s == tmp) <<endl;
        IC(s.size(), startIndex, tmp, s == tmp);

        if (startIndex >= s.size()) {
            if (s.size() == tmp.size()) result = true;
            return;
        }

        for (const auto &item: wordDict) {
            bool had = true;
            for (int i = 0; i < item.size() && startIndex + i < s.size(); i++) {
                if (s[startIndex + i] != item[i]) {
                    had = false;
                    break;
                }
            }

            if (had) {
                IC(item);

                backtracking(
                        s,
                        wordDict,
                        startIndex + item.size(),
                        tmp + item
                );
            }
        }

    }
    // function start.
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        result = false;
        backtracking(s, wordDict, 0, "");
        return result;
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


