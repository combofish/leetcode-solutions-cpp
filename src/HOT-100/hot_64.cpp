/**
-- question: 最小路径和
-- method: 动态规划

--result:

-- analyse:
Time: O(mn)
Space: O(n)
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid.front().size();

        vector<int> dp(n, 0);
        for (int j = 0; j < n; j++)
            if (j == 0) dp[j] = grid.front()[0];
            else dp[j] = grid.front()[j] + dp[j - 1];

        IC(grid);
        IC(dp);
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) dp[j] += grid[i][j];
                else
                    dp[j] = std::min(dp[j - 1], dp[j]) + grid[i][j];
            }
            IC(dp);
        }

        IC(dp);


        return dp.back();
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    int rel = 7;
    IC(grid, rel);
    IC(solution->minPathSum(grid) == rel);
    // code end

    return 0;
}


