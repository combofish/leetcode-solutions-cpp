/**
-- question: 找到字符串中所有字母异位词
-- method:
 - [ ] 滑动窗口
 - [-] 优化的滑动窗口

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), ps = p.size();
        if (n < ps) return {};

        vector<int> ans;
        vector<int> cnt(26);

        for (int i = 0; i < ps; i++) {
            cnt[s[i] - 'a']++;
            cnt[p[i] - 'a']--;
        }

        int differ = 0;
        for (const auto &item: cnt) if (item) ++differ;

        if (!differ) ans.emplace_back(0);

        for (int i = ps; i < n; i++) {
            out_vec(cnt);
            if (cnt[s[i - ps] - 'a'] == 1) --differ;
            else if (cnt[s[i - ps] - 'a'] == 0) ++differ;

            --cnt[s[i - ps] - 'a'];

            out_vec(cnt);
            if (cnt[s[i] - 'a'] == -1) --differ;
            else if (cnt[s[i] - 'a'] == 0) ++differ;
            ++cnt[s[i] - 'a'];

            if (!differ) ans.emplace_back(i - ps + 1);

        }
        return ans;

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "cbaebabacd", p = "abc";
    vector<int> ans = {0, 6};

    IC(s, p, ans);

    IC(solution->findAnagrams(s, p));
    // code end

    return 0;
}


