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
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid.front().front() == 1) return 0;
        vector<int> dp(obstacleGrid.front().size(), 0);
        for (int i = 0; i < dp.size(); i++) {
            if (i == 0) dp[i] = 1;
            else if (obstacleGrid[0][i])
                dp[i] = 0;
            else
                dp[i] = dp[i - 1];
        }

        IC(dp);
        for (int i = 1; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < dp.size(); j++) {
                if (obstacleGrid[i][j]) {
                    dp[j] = 0;
                } else if (j != 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp.back();

    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<vector<int>> obstacleGrid = {{0, 0, 0},
                                        {0, 1, 0},
                                        {0, 0, 0}};
    int rel = 2;
    IC(obstacleGrid, rel);
    IC(solution->uniquePathsWithObstacles(obstacleGrid) == rel);
    // code end

    delete solution;
    return 0;
}


