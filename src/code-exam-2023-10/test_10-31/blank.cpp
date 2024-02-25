#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

/**
 * 
0 0 1  0  0 
0 0 0  0  0 
0 0 0  1  0 
1  1 0  1  1 
0 0 0  0 0 


*/


int main(int argc, char const *argv[]) {

    vector<vector<int>> boards = {};
    int m = boards.size(), n = boards.front().size();

    vector<vector<vector<bool>>> used(m, vector<vector<bool>>(n, vector<bool>(4, false)));

    queue<pair<int, int>> qu;
    qu.emplace(0, 4);

    // end node = 4,4
    const int directions[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    bool can_out = false;
    pair<int, int> end_node = {4, 4};


    while (!qu.empty()) {
        int sz = qu.size();

        while (sz-- > 0) {
            auto node = qu.front();
            qu.pop();

            for (int k = 0; k < 4; ++k) {
                auto direction = directions[k];
                if (used[node.first][node.second][k]) continue;// 已经找过的

                auto curr_node = node;

                while(can_next(curr_node)){
                    curr_node = {curr_node.first + direction[0], curr_node.second + direction[1]};
                }

                if (!used[nx][ny][k]) {
                    used[nx][ny][k] = true;
                    qu.emplace(nx, ny);
                }
            }
        }
    }


    return 0;
}
