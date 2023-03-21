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
    bool isAnagram(string s, string t) {
        int record[26] = {0};

        for (auto c: s)
            record[c - 'a']++;

        for (auto c: t)
            record[c - 'a']--;

        for (int i = 0; i < 26; i++)
            if (record[i] != 0)
                return false;

        return true;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "anagram", t = "nagaram";

    IC(s, t);
    IC(solution->isAnagram(s, t));
    // code end

    delete solution;
    return 0;
}
