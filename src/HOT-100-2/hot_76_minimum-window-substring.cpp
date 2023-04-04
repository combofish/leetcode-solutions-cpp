/**
-- question: 最小覆盖子串
-- method:
 - [ ] 滑动窗口

--result:

-- analyse:
Time: O( C x |s| + |t| )
Space: O(c)
 */

#include "../combofish_utils.hpp"

class Solution {

    // function start.
public:
    string minWindow(string s, string t) {
        int sz = s.size(), tz = t.size();
        if (sz < tz) return "";

        unordered_map<char, int> ori, cnt;
        for (const auto &c: t) ori[c]++;

        IC(ori);

        int slow = 0, fast = -1;
        int ans = sz + 1, resL = -1;
        while (fast < sz) {
            if (ori.count(s[++fast])) ++cnt[s[fast]];

//            IC(ori, cnt);

            while (check(ori, cnt) && slow <= fast) {
                if (fast - slow + 1 < ans) {
                    ans = fast - slow + 1;
                    resL = slow;

//                    IC(s.substr(resL, ans));
                }
                IC(s.substr(slow, ans));

                if (ori.count(s[slow])) --cnt[s[slow]];
                ++slow;
            }
        }

        if (resL == -1) return "";
        return s.substr(resL, ans);

    }

private:

    bool check(const unordered_map<char, int> &ori, unordered_map<char, int> &cnt) {
        for (const auto &item: ori) {
            if (cnt[item.first] < item.second) return false;
        }
        return true;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "ADOBECODEBANC", t = "ABC";
    string ans = "BANC";

    IC(s, t, ans);
    IC(solution->minWindow(s, t));

    // code end

    return 0;
}
