#include <iostream>
#include <vector>

#include <icecream.hpp>

using namespace std;

/**
 * 正确解法使用 dp
 */


const int dirs[2][2] = {{1, 0},
                        {0, 1}};

int cnt;
int n, m;
const int mod = 10000;

void traversal(const vector<vector<int>> &rec, int x, int y, int left, int step) {
    auto s = step + 1;
    while (s--)
        cout << "-";
    cout << ">(" << x + 1 << "," << y + 1 << ")," << left << " ";

    if (x == n - 1 && y == m - 1) {
        ++cnt;
        cnt %= mod;
        cout << endl;
        return;
    }

//    if (left == 0) left = rec[x][y];
    // else left--;

    for (auto &dir: dirs) {
        auto nx = x + dir[0];
        auto ny = y + dir[1];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            auto tmp = left;
            if (tmp) {
                traversal(rec, nx, ny, tmp - 1, step + 1);
            } else {
                tmp = rec[x][y];
                while (tmp--) {
                    traversal(rec, nx, ny, tmp, step + 1);
                }
            }
        }

    }


}

int count_path(const vector<vector<int>> &rec) {
    cnt = 0;
    int x = 0, y = 0;


    traversal(rec, x, y, 0, 0);

    return cnt;
}

int main() {

    int T;
//    cin >> T;
    T = 1;

    while (T--) {
//        cin >> n >> m;
//        vector<vector<int>> rec(n, vector<int>(m, 0));
//
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) {
//                cin >> rec[i][j];
//            }
//        }

        n = 3;
        m = 3;
        vector<vector<int>> rec = {{2, 1, 1},
                                   {1, 1, 1},
                                   {1, 1, 1}};
        cout << count_path(rec) << endl;
    }


    return 0;
}
