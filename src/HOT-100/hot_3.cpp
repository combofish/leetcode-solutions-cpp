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
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();
        int result = 0;

        int slow = 0;
        unordered_map<char, int> umap;
        while (slow < s.size()) {
            umap.clear();
            int i = slow;
            while (i < s.size() && umap.find(s[i]) == umap.end()) {
                umap[s[i]] = i;
                i++;
            }

            if (umap.size() > result) result = umap.size();
            if (i >= s.size()) return result;
            slow = umap[s[i]] + 1;

            IC(umap, i, s[i], slow);
        }


        return result;

    }

    /**
     *
     * @param s
     * @return
     */
    int lengthOfLongestSubstring_2(string s) {
        unordered_set<char> occ;
        int n = s.size();
        int rk = -1, ans = 0;
        for (int i = 0; i < n; i++) {
            if (i != 0) occ.erase(s[i - 1]);
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                occ.insert(s[rk + 1]);
                ++rk;
            }

            ans = std::max(ans, rk - i + 1);
            IC(occ, i, rk, ans);
        }

        return ans;
    }


    int lengthOfLongestSubstring_3(string s) {
        if (s.size() <= 1) return s.size();
        unordered_set<char> occ;
        int ans = 0, rk = -1;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (i != 0) {
                occ.erase(s[rk - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                occ.insert(s[rk + 1]);
                rk++;
            }

            ans = std::max(ans, rk + 1 - i);
        }

        return ans;
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "abcabcbb";
    int rel = 3;

    IC(s, rel, s.size());
    IC(solution->lengthOfLongestSubstring(s) == rel);

    IC();
    IC(solution->lengthOfLongestSubstring_2(s) == rel);

    IC();
    IC(solution->lengthOfLongestSubstring_3(s) == rel);

    // code end

    delete solution;
    return 0;
}


