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
public:
    // function start.
    static bool repeatedSubstringPattern(string s) {
        auto getNext = [](int *next, const string &s) {
            int j = -1;
            next[0] = j;

            for (int i = 1; i < s.size(); ++i) {
                while (j >= 0 && s[i] != s[j + 1]) j = next[j];
                if (s[i] == s[j + 1]) j++;
                next[i] = j;
            }
        };

        if (s.size() == 0) return false;
        int next[s.size()];
        getNext(next, s);

        for (int i = 0; i < s.size(); i++)
            IC(i, next[i]);

        int len = s.size();
        IC(len);
        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0)
            return true;
        return false;


    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "abcabcabcabc";
    bool rel = true;
    IC(s, rel);

    IC(solution->repeatedSubstringPattern(s) == rel);
    // code end

    delete solution;
    return 0;
}


