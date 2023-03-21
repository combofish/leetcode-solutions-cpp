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
    string replaceSpace(string s) {
        string res;
        for (auto c: s)
            if (c == ' ') res += "%20";
            else
                res += c;
        return res;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "We are happy.";
    string rel = "We%20are%20happy.";
    IC(s, rel);

    string res = solution->replaceSpace(s);
    IC(res, res == rel);
    // code end

    delete solution;
    return 0;
}
