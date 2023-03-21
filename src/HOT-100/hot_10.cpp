/**
-- method:

--result:

-- analyse:
Time: O(mn)
Space: O(mn)

 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    /**
     * 动态规划
     * @param s
     * @param p
     * @return
     */
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) return false;
            if (p[j - 1] == '.') return true;
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        f.front().front() = true;

        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {


                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1))
                        f[i][j] |= f[i - 1][j];
                } else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }

//                IC(i,j, f);
		
            }
        }

        IC(f);
        return f.back().back();
    }

private:
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "abbbbc", p = "ab*d*c";
    bool rel = true;
    IC(s, p, rel);

    IC(solution->isMatch(s, p) == rel);
    // code end

    delete solution;
    return 0;
}
