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
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        IC(dp);

        for (int j = 1; j < m; j++) {
            for (int i = 1; i < n; i++) {
                dp[i] += dp[i - 1];
            }
            IC(dp);
        }


        IC(dp);
        return dp.back();

    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    int m = 3, n = 7, rel = 28;
    IC(m, n, rel);

    IC(solution->uniquePaths(m, n) == rel);


    // code end

    delete solution;
    return 0;
}


