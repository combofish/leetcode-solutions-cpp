/**
-- question: 回文子串
-- method:
 - [ ] 中心拓展
 - [-] Manacher 算法
 - [ ] DP

--result:

-- analyse:
Time: O(n^2)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int countSubstrings(string s) {
        int n = s.size();
        string t = "$#";
        for (const auto &c: s) {
            t += c;
            t += '#';
        }

        n = t.size();
        t += '!';
        IC(s, n, t);


        vector<int> f(n);
        int iMax = 0, rMax = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            // 初始化
            f[i] = (i <= rMax) ? std::min(rMax - i + 1, f[2 * iMax - i]) : 1;

            // 中心扩展
            while (t[i + f[i]] == t[i - f[i]]) ++f[i];

            // 动态维护 iMax 和 rMax
            if (i + f[i] - 1 > rMax) {
                iMax = i;
                rMax = i + f[i] - 1;
            }

            // 统计答案
            ans += (f[i] / 2);
        }

        IC(f);

        return ans;

    }

private:


    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "abc";
    int ans = 3;
    IC(s, ans);

    IC(solution->countSubstrings(s));
    // code end

    return 0;
}


