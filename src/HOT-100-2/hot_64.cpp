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
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid.front().size();

        // vector<vector<int>> dp(m, vector<int>(n,0));
        // dp.front().front() = grid.front().front();

        // 直接在原矩阵上操作

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i && !j) continue;
                else if (i == 0 && j > 0) {
                    grid[i][j] += grid[i][j - 1];
                } else if (j == 0 && i > 0) {
                    grid[i][j] += grid[i - 1][j];
                } else {
                    grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }

        IC(grid);

        return grid.back().back();
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int ans = 7;

    IC(grid, ans);


    IC(solution->minPathSum(grid));
    // code end

    return 0;
}
