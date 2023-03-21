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
        unordered_map<char, int> umap1;

        for (auto c: s)
            umap1[c]++;

        for (auto c: t)
            umap1[c]--;

        for (auto k: umap1)
            if (k.second != 0)
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
