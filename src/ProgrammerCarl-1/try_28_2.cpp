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
    void getNext(int *next, const string &s) {
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); ++i) {
            while (j > 0 && s[i] != s[j]) j = next[j - 1];
            if (s[i] == s[j]) j++;
            next[i] = j;

            cout << " " << i << " : " << j << endl;
        }
    }

    // function start.
    int strStr(string haystack, string needle) {
        if (0 == needle.size()) return 0;
        int next[needle.size()];
        getNext(next, needle);

        int j = 0;
        for (int i = 0; i < haystack.size(); ++i) {
            while (j > 0 && haystack[i] != needle[j]) j = next[j - 1];
            if (haystack[i] == needle[j]) ++j;
            if (j == needle.size()) return (i - needle.size() + 1);
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
