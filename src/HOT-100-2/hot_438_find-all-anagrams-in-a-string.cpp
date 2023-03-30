/**
-- question: 找到字符串中所有字母异位词
-- method:
 - [-] 滑动窗口
 - [ ] 优化的滑动窗口

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

        vector<int> ans, sCnt(26), pCnt(26);
        for (int i = 0; i < ps; i++) {
            ++sCnt[s[i] - 'a'];
            ++pCnt[p[i] - 'a'];
        }

        if (sCnt == pCnt) ans.emplace_back(0);

        for (int i = ps; i < n; i++) {
            sCnt[s[i] - 'a']++;
            sCnt[s[i - ps] - 'a']--;

            if (sCnt == pCnt) ans.emplace_back(i - ps + 1);
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


