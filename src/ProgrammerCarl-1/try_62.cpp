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
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int i = 1; i<m; i++){
            for(int j = 1; j<n;j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        IC(dp);
        return dp.back().back();
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    int m = 3, n = 7, rel = 28;
    IC(m, n, rel);

    IC(solution->uniquePaths(m, n)  == rel);


    // code end

    delete solution;
    return 0;
}


