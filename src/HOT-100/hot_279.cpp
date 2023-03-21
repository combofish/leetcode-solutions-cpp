/**
-- question: 完全平方数
-- method:
 - [*] 动态规划

--result:

-- analyse:
Time: O(n ^(3/2)) 
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <climits>

class Solution {

    // function start.
public:
    int numSquares(int n) {
        auto dp = vector<int>(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int minN = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                minN = std::min(minN, dp[i - j * j]);
            }

            dp[i] = minN + 1;
        }

        return dp.back();
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int n = 13, rel = 2;
    IC(n, rel);
    IC(solution->numSquares(n));

    // code end

    return 0;
}
