/**
-- question: 爬楼梯
-- method: 动态规划

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    int climbStairs(int n) {
        if (n < 3) return n;

        vector<int> dp(n + 1, 0);

        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 2] + dp[i - 1];

        return dp.back();


    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int n = 3, rel = 3;
    IC(n, rel);

    IC(solution->climbStairs(n) == rel);
    // code end

    return 0;
}


