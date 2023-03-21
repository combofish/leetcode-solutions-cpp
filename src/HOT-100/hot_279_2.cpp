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
        auto dp = vector<int>(n + 1, INT_MAX);
        dp.front() = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j * j <= i; j++)
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);

        IC(dp);
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
