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

class Solution {

    // function start.
public:
    int orangesRotting(vector<vector<int>> &grid) {
        queue<pair<int, int>> qu;
        int cnt_fresh = 0;
        const int dirs[4][2] = {{-1, 0},
                                {0,  -1},
                                {1,  0},
                                {0,  1}};

        int m = grid.size();
        int n = grid.front().size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) ++cnt_fresh;
                else if (grid[i][j] == 2) {
                    qu.push({i, j});
                }
            }
        }
        if (cnt_fresh == 0) return 0;

        int days = 0;
        while (!qu.empty()) {
            int sz = qu.size();
            bool expand = false;
            while (sz--) {
                auto points = qu.front();
                qu.pop();
                for (auto &dir: dirs) {
                    auto nx = points.first + dir[0];
                    auto ny = points.second + dir[1];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        expand = true;
                        grid[nx][ny] = 2;
                        qu.push({nx, ny});
                        --cnt_fresh;
                    }
                }

            }
            if (expand) ++days;
        }


        return cnt_fresh ? -1 : days;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<vector<int>> grid = {{0, 1}};
    IC(grid);
    IC(solution->orangesRotting(grid));
    // code end

    return 0;
}