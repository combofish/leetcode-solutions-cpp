/**
-- question: 不同路径
-- method: dp

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
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
    int m = 3, n = 7;
    int rel = 28;
    IC(m, n, rel);
    IC(solution->uniquePaths(m, n) == rel);
    // code end

    return 0;
}


