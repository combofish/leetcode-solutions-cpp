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

    int numIslands(vector<vector<char>> &grid) {
        int ans = 0;
        auto m = grid.size();
        auto n = grid.front().size();

        vector<vector<int>> used(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (used[i][j] || grid[i][j] == '0') continue;

                if (grid[i][j] == '1') {
                    expanding(grid, used, i, j, ++ans);
                    // used[i][j] = false;
                }
            }
        }

        IC(used);
        return ans;
    }

private:
    void expanding(const vector<vector<char>> &grid, vector<vector<int>> &used, int i, int j, int ans) {
        used[i][j] = ans;

        auto m = grid.size();
        auto n = grid.front().size();

        for (auto &item: dirs) {
            auto nx = i + item[0];
            auto ny = j + item[1];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1' && !used[nx][ny]) {
                expanding(grid, used, nx, ny, ans);
            }
        }

    }

    const int dirs[4][2] = {{1,  0},
                            {0,  1},
                            {-1, 0},
                            {0,  -1}};
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start


    vector<vector<char>> grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
    };
    int ans = 3;

    IC(grid, ans);

    IC(solution->numIslands(grid));


    // code end

    return 0;
}


