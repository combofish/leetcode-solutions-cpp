#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid.front().size();

        int cnt = 0;
        const int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        for(int i = 0; i< m; ++i){
            for(int j = 0; j< n; ++j){
                if(grid[i][j] == '0') continue;

                ++cnt;
                grid[i][j] = '0';
                queue<pair<int,int>> qu;
                qu.emplace(i,j);

                while(!qu.empty()){
                    IC(qu.size());

                    auto node = qu.front();qu.pop();
                    for(auto &dir: directions){
                        auto nx = node.first + dir[0], ny = node.second + dir[1];
                        if(nx >= 0 && nx < m && ny >=0 && ny < n && grid[nx][ny] == '1'){
                            grid[nx][ny] = '0';
                            qu.emplace(nx, ny);
                        }
                    }
                }
            }
        }
        return cnt;
        
    }
};

int main(int argc, char const *argv[]) {

    // string s = "ADOBECODEBANC", t = "ABC", ans = "BANC";
    // vector<vector<char>> grid = {
    //         {'1', '1', '1', '1', '0'},
    //         {'1', '1', '0', '1', '0'},
    //         {'1', '1', '0', '0', '0'},
    //         {'0', '0', '0', '0', '0'}};

        vector<vector<char>> grid = {
            {'1', '1', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '1', '1', '1', '1'}};

    int ans = 1;

    // IC(s, t, ans);
    IC(grid, ans);

    Solution sol;
    IC(sol.numIslands(grid));


    return 0;
}
