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
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i = 1; i<=n; i++)
            for(int j  = 1; j<=i;j++)
                dp[i] += dp[j-1] * dp[i-j];

        return dp.back();
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    int n = 3;
    int rel = 5;
    IC(n, rel);
    IC(solution->numTrees(n) == rel);
    // code end

    delete solution;
    return 0;
}


