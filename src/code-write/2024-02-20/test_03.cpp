#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;
class Solution {
    const int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void backtracking(vector<vector<char>> &grid, int i, int j, const int m, const int n) {
        // grid[i][j] = '0';

        for (auto &item: directions) {
            auto nx = i + item[0], ny = j + item[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                grid[nx][ny] = '0';

                // cout<<"Change One <>"<<endl;
                IC(grid);
                backtracking(grid, nx, ny, m, n);
            }
        }

        // IC(grid);
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size(), n = grid.front().size();

        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') continue;

                ++cnt;
                grid[i][j] = '0';
                backtracking(grid, i, j, m, n);
                IC(cnt, grid);

                cout<<endl<<endl;
            }
        }

        return cnt;
    }
};

int main(int argc, char const *argv[]) {

    // string s = "ADOBECODEBANC", t = "ABC", ans = "BANC";
    vector<vector<char>> grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}};

    int ans = 1;

    // IC(s, t, ans);
    IC(grid, ans);

    Solution sol;
    IC(sol.numIslands(grid));


    return 0;
}
