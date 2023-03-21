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
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin());
        t.erase(t.end() - 1);
        if (t.find(s) != std::string::npos) return true;
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

    IC(solution->repeatedSubstringPattern(s));
    // code end

    delete solution;
    return 0;
}
