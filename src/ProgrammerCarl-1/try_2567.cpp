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
    string reverseLeftWords(string s, int n) {
        std::reverse(s.begin(), s.end());
        IC(s);

        std::reverse(s.begin(), s.begin() + s.size() - n);
        std::reverse(s.begin() + s.size() - n, s.end());

        return s;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "abcdefg";
    int k = 2;
    string rel = "cdefgab";
    IC(s, k, rel);
    string res = solution->reverseLeftWords(s, k);
    IC(res, res == rel);
    // code end

    delete solution;
    return 0;
}
