/**
-- question: 不同的二叉搜索树
-- method:
 - [*] 动态规划

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
    int numTrees(int n) {
        auto dp = vector<int>(n + 1);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[i - j] * dp[j - 1];
                IC(i, i - j, j - 1);
            }

            IC(dp);
        }

        return dp.back();
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int n = 3;
    int rel = 5;
    IC(n, rel);

    IC(solution->numTrees(n));

    // code end

    return 0;
}
