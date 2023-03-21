/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        vector<int> dp(n, 0);
        dp.front() = 1;
        dp[1] = 2;

        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
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
    int res = 3;
    IC(n, res);

    IC(solution->climbStairs(n));
    // code end

    return 0;
}
