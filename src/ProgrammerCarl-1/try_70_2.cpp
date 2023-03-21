/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
private:

    // function start.
public:
    /**
     * view as complete pack problem
     * @param n
     * @return
     */
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp.front() = 1;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= 2; j++)
                if (i - j >= 0) dp[i] += dp[i - j];

        return dp.back();
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    int n = 3;
    int rel = 3;
    IC(n, rel);
    IC(solution->climbStairs(n));
    // code end

    delete solution;
    return 0;
}


