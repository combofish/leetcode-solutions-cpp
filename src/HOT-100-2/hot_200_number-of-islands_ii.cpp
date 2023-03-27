/**
-- question: 岛屿数量
-- method:
 - []
 - [-] stack

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

        const int dirs[4][2] = {{1,  0},
                                {0,  1},
                                {0,  -1},
                                {-1, 0}};
        vector<vector<bool>> used(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (used[i][j] || grid[i][j] == '0') continue;
                else {
                    ++ans;

                    stack<pair<int, int>> st;
                    st.emplace(i, j);
                    used[i][j] = true;

                    while (!st.empty()) {
                        auto point = st.top();
                        st.pop();

                        for (auto &item: dirs) {
                            auto nx = point.first + item[0];
                            auto ny = point.second + item[1];

                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1' && !used[nx][ny]) {
                                used[nx][ny] = true;
                                st.emplace(nx, ny);
                            }
                        }

                    }
                }


            }
        }

        return ans;
    }

private:
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


