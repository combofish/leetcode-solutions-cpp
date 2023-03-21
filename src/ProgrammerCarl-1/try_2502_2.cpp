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
        int cnt = 0;
        int n = s.size();
        for (auto c: s)
            if (c == ' ') cnt++;

        s.resize(s.size() + 2 * cnt);
        int new_n = s.size();

        //        for (int right = new_n - 1, left = n - 1; right >= 0; right--, left--) {
        for (int right = new_n - 1, left = n - 1; left < right; right--, left--) {
            if (s[left] != ' ')
                s[right] = s[left];
            else {
                s[right] = '0';
                s[right - 1] = '2';
                s[right - 2] = '%';
                right -= 2;
            }
        }
        return s;
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
