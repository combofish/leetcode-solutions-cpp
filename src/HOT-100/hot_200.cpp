/**
-- question: 岛屿数量
-- method:
 - [ ] 广度优先搜索

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
        int m = grid.size();
        int n = grid.front().size();

        int result = 0;
        const int directions[4][2] = {{-1, 0},
                                      {0,  -1},
                                      {0,  1},
                                      {1,  0}};
        vector<vector<bool>> used(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (used[i][j] || grid[i][j] == '0') continue;
                else {
                    // grid[i][j] == '1'
                    ++result;
                    used[i][j] = true;
                    queue<pair<int, int>> points;
                    points.push({i, j});

                    while (!points.empty()) {
                        auto curPoint = points.front();
                        points.pop();

                        for (const auto &item: directions) {
                            int nI = curPoint.first + item[0];
                            int nJ = curPoint.second + item[1];
                            if (nI >= 0 && nI < m && nJ >= 0 && nJ < n && grid[nI][nJ] == '1' && !used[nI][nJ]) {
                                used[nI][nJ] = true;
                                points.push({nI, nJ});
                            }
                        }
                    }

                    IC(used);

                }
            }
        }

        return result;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};
    int rel = 3;
    IC(grid, rel);
    IC(solution->numIslands(grid) == rel);
    // code end

    return 0;
}


