#include <iostream>

#include <icecream.hpp>
#include <queue>
using namespace std;


int main() {
    int n;
    int m;

    n = 3;
    m = 4;

    vector<vector<char>> board(n, vector<char>(m, ' '));

    board = {
            {'.', '.', '.', '.'},
            {'*', '*', '.', '*'},
            {'.', '.', '.', '.'}};

    vector<vector<bool>> used(n, vector<bool>(m, 0));

    const int directions[3][2] = {{1, 0}, {0, 1}, {1, 1}};
    queue<pair<int, int>> qu;
    int step = 0;
    qu.emplace(0, 0);
    used.front().front() = true;

    while (!qu.empty()) {
        int sz = qu.size();
        ++step;
        while (sz--) {
            auto point = qu.front();
            qu.pop();

            int i = point.first, j = point.second;
            for (const auto direction: directions) {
                int k = 1;

                while (1) {
                    int ni = i + direction[0] * k;
                    int nj = j + direction[1] * k;

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && board[ni][nj] == '.' && !used[ni][nj]) {
                        used[ni][nj] = true;
                        qu.emplace(ni, nj);

                        if (ni == n - 1 && nj == m - 1) {
                            cout << step << endl;
                            cout << "END" << endl;
                        }
                    } else {
                        break;
                    }
                    ++k;
                }
            }
        }
    }


    cout << -1 << endl;

    return 0;
}