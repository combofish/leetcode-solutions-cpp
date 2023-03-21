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
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap;
        // int record[26] = {0};

        for (auto c: magazine) umap[c]++;

        for (auto c: ransomNote) {
            umap[c]--;
            if (umap[c] < 0) {
                return false;
            }
        }

        return true;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    bool res = false;
    string ransomNote = "a", magazine = "b";
    IC(ransomNote, magazine, res);

    IC(solution->canConstruct(ransomNote, magazine));
    // code end

    delete solution;
    return 0;
}
