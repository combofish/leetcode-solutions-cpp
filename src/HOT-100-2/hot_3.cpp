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

        auto rec = unordered_set<char>();
        int n = s.size();

        int rk = -1, ans = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                rec.erase(s[i - 1]);
            }

            while (rk + 1 < n && !rec.count(s[rk + 1])) {
                rec.insert(s[rk + 1]);
                ++rk;
            }
            ans = std::max(ans, rk - i + 1);
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
