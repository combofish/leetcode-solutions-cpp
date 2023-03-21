/**
-- question: 剪绳子
-- method:
 - [ ] 动态规划

--result:

-- analyse:
Time: O(n^2)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int cuttingRope(int n) {
        auto dp = vector<int>(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            int curMax = 0;
            for (int j = 1; j < i; j++)
                curMax = std::max({curMax, j * (i - j), j * dp[i - j]});

            dp[i] = curMax;
        }

        return dp.back();
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int n = 10;
    int rel = 36;
    string res = "10 = 3 + 3 + 4, 3 × 3 × 4 = 36";
    IC(n, rel, res);
    IC(solution->cuttingRope(n));
    // code end

    return 0;
}
