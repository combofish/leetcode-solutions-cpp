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
#include <system_error>

class Solution {
public:
    // function start.
    string reverseWords(string s) {
        int fast = 0;
        int slow = 0;
        int n = s.size();
        int last = n - 1;

        // while (s[fast] == ' ' && fast < n) fast++;
        // while (s[last] == ' ' && last >= 0) last--;

        // for (; fast <= last; fast++) {
        //     if (fast > 0 && s[fast] == ' ' && s[fast - 1] == ' ')
        //         continue;
        //     else {
        //         s[slow] = s[fast];
        //         slow++;
        //     }
        // }
        for (; fast < n; fast++) {
            if (s[fast] != ' ') {
                if (slow != 0) s[slow++] = ' ';
                while (s[fast] != ' ' && fast < n)
                    s[slow++] = s[fast++];
            }
        }

        IC(s, slow, fast);
        s.resize(slow);
        std::reverse(s.begin(), s.end());
        IC(s, slow, fast);

        slow = 0;
        fast = 0;
        for (; fast <= s.size(); fast++) {
            if (fast == s.size() || s[fast] == ' ') {
                std::reverse(s.begin() + slow, s.begin() + fast);
                slow = fast + 1;
            }
        }

        // if(fast> slow)
        //   std::reverse(s.begin()+slow, s.end());


        return s;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "  the sky  is  blue  ";
    string rel = "blue is sky the";
    IC(s, rel);
    string res = solution->reverseWords(s);
    IC(res, res == rel);
    // code end

    delete solution;
    return 0;
}
