/**
-- method:

--result:

-- analyse:
Time: O(n^2)
Space: O(n)

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
private:

    // function start.
public:
    /**
     * dp
     * @param n
     * @return
     */
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i - 1; j++) {
                IC(i,j);
                dp[i] = std::max(dp[i], std::max((i - j) * j, dp[i - j] * j));
            }
        }
        IC(dp);
        return dp.back();
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    int n = 10;
    int rel = 36;
    vector<int> res = {3, 3, 4};
    IC(n, rel, res);
    IC(solution->integerBreak(n));

    // code end

    delete solution;
    return 0;
}


