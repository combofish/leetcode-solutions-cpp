/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <string>

class Solution {
public:

    // function start.
    int strStr(string haystack, string needle) {

        auto getNext = [](int *next, const string &s){
            int j = -1;
            next[0] = j;
            for (int i = 1; i < s.size(); i++) {
                while (j >= 0 && s[i] != s[j + 1]) j = next[j];

                if (s[i] == s[j + 1]) ++j;

                next[i] = j;

                // debug
                IC(i, j);
            }
        };

        if (needle.size() == 0) return 0;
        int next[needle.size()];


        getNext(next, needle);

        out_line();
        for (int t = 0; t < needle.size(); ++t) cout << t << " ";
        out_line();
        for (int t = 0; t < needle.size(); ++t) cout << next[t] << " ";
        out_line();


        int j = -1;
        for (int i = 0; i < haystack.size(); ++i) {
            while (j >= 0 && haystack[i] != needle[j + 1]) j = next[j];
            if (haystack[i] == needle[j + 1]) ++j;
            if (j == (needle.size() - 1)) return (i - needle.size() + 1);
        }

        return -1;
    }


    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    // string haystack = "hello";
    // string needle = "ll";
    int rel = 3;
    std::
    //std::string

    string haystack = "aabaabaafa";
    string needle = "aabaaf";
    IC(haystack, needle, rel);

    int res = solution->strStr(haystack, needle);
    IC(res, res == rel);
    // code end

    delete solution;
    return 0;
}
