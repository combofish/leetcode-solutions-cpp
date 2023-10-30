#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

// 赵立明
int main(int argc, char const *argv[]) {
    vector<vector<int>> boards = {
            {1, 0, 0, 0, 1},
            {1, 0, 1, 0, 0}};

    int m = boards.size(), n = boards.front().size();

    const int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int cnt = 0;
    queue<pair<int, int>> qu;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (boards[i][j] == 1) {
                ++cnt;

                boards[i][j] = 0;
                qu.emplace(i, j);

                while (!qu.empty()) {
                    auto node = qu.front();
                    qu.pop();

                    for (auto &direction: directions) {
                        auto nx = node.first + direction[0], ny = node.second + direction[1];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && boards[nx][ny] == 1) {
                            boards[nx][ny] = 0;
                            qu.emplace(nx, ny);
                        }
                    }
                }

                IC(boards, cnt);
            }
        }
    }

    IC(cnt);


    return 0;
}
