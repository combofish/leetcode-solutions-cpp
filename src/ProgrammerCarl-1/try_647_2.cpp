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

    int countSubstrings(string s) {
        int result = 0;

        int n = s.size();
        auto extend = [&s, &n](int i, int j) {
            int res = 0;
            while (i >= 0 && j < n && s[i] == s[j]) {
                i--;
                j++;
                res++;
            }
            return res;
        };

        for (int i = 0; i < n; i++) {
            result += extend(i, i);
            result += extend(i, i + 1);
        }

        return result;
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "aaa";
    int rel = 6;
    vector<string> rel_s = {"a", "a", "a", "aa", "aa", "aaa"};

    IC(s, rel, rel_s);
    IC(solution->countSubstrings(s) == rel);

    // code end

    delete solution;
    return 0;
}


