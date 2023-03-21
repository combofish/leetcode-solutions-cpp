/**
   -- question: 找到字符串中所有字母异位词
   -- method:
   - [ ] 滑动窗口
   - [*] 优化的滑动窗口
   
   --result:

   -- analyse:
   Time: O(n+m+E)
   Space: O(E)
*/

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        if (sLen < pLen) return vector<int>();
        vector<int> res, cache(26);
        for (int i = 0; i < pLen; i++) {
            cache[s[i] - 'a']++;
            cache[p[i] - 'a']--;
        }

        int differ = 0;
        for (int i = 0; i < 26; i++)
            if (cache[i]) ++differ;

        if (!differ) res.emplace_back(0);

        for (int i = 0; i < sLen - pLen; i++) {
            fmt::print("{}\n", fmt::join(cache, ","));
            //      fmt::print("use\n");

            int tmp = s[i] - 'a';
            if (cache[tmp] == 1) --differ;
            else if (cache[tmp] == 0)
                ++differ;
            --cache[tmp];

            tmp = s[i + pLen] - 'a';
            if (cache[tmp] == -1) --differ;
            else if (cache[tmp] == 0)
                ++differ;
            ++cache[tmp];

            if (!differ) res.emplace_back(i + 1);
            // fmt::print("{}, {}\n", cache, differ);
            //IC(cache, differ);
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
