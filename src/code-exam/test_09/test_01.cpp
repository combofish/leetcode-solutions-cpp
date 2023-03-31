//
// Created by larry on 23-3-31.
//

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {

    int m, n;
    // cin>>m>>n;

    m = 3;
    n = 3;

    vector<vector<int>> aImg(m, vector<int>(n, 0));
    vector<vector<int>> bImg(m, vector<int>(n, 0));

//    for (int i = 0; i < m; i++)
//        for (int j = 0; j < n; j++)
//            cin >> aImg[i][j];
//
//    for (int i = 0; i < m; i++)
//        for (int j = 0; j < n; j++)
//            cin >> bImg[i][j];


    aImg = {
            {1, 0, 1},
            {0, 0, 1},
            {1, 1, 0}
    };
    bImg = {
            {1, 1, 0},
            {0, 0, 1},
            {0, 0, 1}
    };

    int tot = m * n;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (aImg[i][j] == bImg[i][j]) {
                ++ans;
            }
        }
    }

    double res = 100.0 * (double) ans / tot;
//    cout << res << setprecision(2) << endl;
    ::printf("%.2f\n", res);


    return 0;
}