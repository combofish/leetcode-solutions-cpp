/**
-- question: 找到字符串中所有字母异位词
-- method:
 - [*] 滑动窗口
 - [ ] 优化的滑动窗口
 
--result:

-- analyse:
Time: O(m + (n-m)*E)
Space: O(E)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();

        if (sLen < pLen) return vector<int>();
        auto res = vector<int>();
        auto recS = vector<int>(26);
        auto recP = vector<int>(26);

        for (int i = 0; i < pLen; i++) {
            recP[p[i] - 'a']++;
            recS[s[i] - 'a']++;
        }

        if (recS == recP) res.emplace_back(0);
        for (int i = 0; i < sLen - pLen; i++) {
            recS[s[i] - 'a']--;
            recS[s[i + pLen] - 'a']++;
            if (recS == recP) res.emplace_back(i + 1);
        }
        return res;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "cbaebabacd", p = "abc";
    vector<int> resl = {0, 6};
    IC(s, p, resl);

    IC(solution->findAnagrams(s, p));

    // code end

    return 0;
}
