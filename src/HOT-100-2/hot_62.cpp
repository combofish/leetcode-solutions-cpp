/**
-- question: 不同路径
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
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        m--;
        while (m--) {
            for (int i = 1; i < n; i++) {
                dp[i] += dp[i - 1];
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
    int ans = 28;

    IC(m, n, ans);
    IC(solution->uniquePaths(m, n));

    // code end

    return 0;
}
