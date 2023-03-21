/**
-- question: 最小覆盖子串
-- method:
 - [*] 滑动窗口

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <climits>
#include <unordered_map>

class Solution {

    // function start.
public:
    string minWindow(string s, string t) {
        int sn = s.size();
        int tn = t.size();

        if (sn < tn) return "";

        unordered_map<char, int> cache;
        unordered_map<char, int> ori;
        for (const auto &item: t) ++ori[item];

        int slow = 0, fast = -1;
        int len = INT_MAX, ansL = -1;
        while (fast < sn) {
            if (ori.find(s[++fast]) != ori.end()) ++cache[s[fast]];

            while (isValid2(cache, ori) && slow <= fast) {
                IC(cache);

                if (fast - slow + 1 < len) {
                    len = fast - slow + 1;
                    ansL = slow;
                }

                if (ori.count(s[slow])) --cache[s[slow]];
                ++slow;
            }
        }

        if (ansL == -1) return "";
        IC(ansL, len);
        return s.substr(ansL, len);
    }

    // bak
    // unordered_map<char, int> ori, cnt;

    // bool check() {
    //     for (const auto &p: ori) {
    //         if (cnt[p.first] < p.second) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // string minWindow(string s, string t) {
    //     for (const auto &c: t) {
    //         ++ori[c];
    //     }

    //     int l = 0, r = -1;
    //     int len = INT_MAX, ansL = -1;

    //     while (r < int(s.size())) {
    //         if (ori.find(s[++r]) != ori.end()) {
    //             ++cnt[s[r]];
    //         }
    //         while (check() && l <= r) {
    //             IC(cnt, ori);

    //             if (r - l + 1 < len) {
    //                 len = r - l + 1;
    //                 ansL = l;
    //             }
    //             if (ori.find(s[l]) != ori.end()) {
    //                 --cnt[s[l]];
    //             }
    //             ++l;
    //         }
    //     }

    // 	/**
    // 	   ic| ansL: 9, len: 4
    // 	   ic| solution->minWindow(s, t): "BANC"
    // 	 */
    //     IC(ori, cnt);

    //     IC(ansL, len);
    //     return ansL == -1 ? string() : s.substr(ansL, len);
    // }


private:
    // error
    // bool isValid(const unordered_map<char, int> &umap, const string &t) {
    //     for (const auto &c: t) {
    //         if (!umap.count(c)) return false;
    //     }

    //     return true;
    // }

    bool isValid2(unordered_map<char, int> &umap, const unordered_map<char, int> &ori) {
        for (const auto &item: ori) {
            if (umap[item.first] < item.second) return false;
        }
        return true;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "ADOBECODEBANC", t = "ABC", rel = "BANC";
    IC(s, t, rel);

    IC(solution->minWindow(s, t));

    // code end

    return 0;
}
