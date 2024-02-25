#include <bits/stdc++.h>
#include <icecream.hpp>
#include <queue>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {

        vector<int> dp = grid.front();
        int m = grid.size(), n = grid.front().size();

        for (int j = 1; j < n; ++j) dp[j] += dp[j - 1];

        IC(dp);

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) dp[0] += grid[i][j];
                else
                    dp[j] = std::min(dp[j], dp[j-1]) + grid[i][j];
            }

            IC(dp);
        }

        return dp.back();
    }
};
int main(int argc, char const *argv[]) {

    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    int ans = 7;

    IC(grid, ans);
    Solution sol;

    IC(sol.minPathSum(grid));

    return 0;
}
