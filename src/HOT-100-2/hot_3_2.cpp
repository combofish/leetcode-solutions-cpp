/**
-- question:
-- method:
 - [*] 滑动窗口

--result:

-- analyse:
Time: O(N)
Space: O(|E|)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int lengthOfLongestSubstring(string s) {

        auto rec = unordered_map<char, int>();
        int ans = 0, rk = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            auto ch = s[i];
            if (rec.count(ch)) {
                rk = std::max(rk, rec[ch] + 1);
            }
            ans = std::max(ans, i - rk + 1);
            rec[ch] = i;

            // rec.insert({ch, i});

            IC(ch, i, rec);
        }

        return ans;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto s = "pwwkew";
    int res = 3;

    IC(s, res);
    IC(solution->lengthOfLongestSubstring(s));

    // code end

    return 0;
}
