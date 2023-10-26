#include <cstring>
#include <icecream.hpp>
#include <iostream>
#include <queue>
using namespace std;

int a, b;
int x00, y00, x11, y11;
const int N = 1010;
int arr[N][N];
// int d[N][N];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};


int traversal(vector<vector<int>> &used) {
    queue<pair<int, int>> qu;
    qu.emplace(x00, y00);

    // memset(d, -1, sizeof(d));


    used[x00][y00] = 0;

    // int x,y;

    while (!qu.empty()) {
        auto node = qu.front();
        qu.pop();

        for (int i = 0; i < 4; ++i) {
            auto x = node.first + dx[i];
            auto y = node.second + dy[i];

            if (x >= 1 && x <= a && y >= 1 && y <= b && used[x][y] == -1 && arr[x][y] == '.') {
                used[x][y] = used[node.first][node.second] + 1;
                qu.emplace(x, y);
            }
        }
    }

    return used[x11][y11];
}

int main() {
    // int a, b;
    // while (cin >> a >> b) { // 注意 while 处理多个 case
    //     cout << a + b << endl;
    // }


    cin >> a >> b;
    cin >> x00 >> y00 >> x11 >> y11;

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> used(a + 1, vector<int>(b + 1, -1));
    int res = traversal(used);

IC(arr);
    IC(used);

    if (res == 0) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")