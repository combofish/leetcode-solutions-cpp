//
// Created by larry on 23-4-1.
//

#include <iostream>
#include <vector>

#include <icecream.hpp>

using namespace std;

const int mod = 1009;

vector<vector<int>> mat_t(const vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat.front().size();

    vector<vector<int>> t(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            t[j][i] = mat[i][j];

    return t;
}

vector<vector<int>> mul(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    int n = a.size();
    int m = a.front().size();
    int q = b.front().size();

    vector<vector<int>> ans(n, vector<int>(q, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < m; k++) {
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= mod;
            }
        }
    }

    return ans;
}

int main() {
    int n, m;

    n = 2;
    m = 2;

    vector<vector<int>> A(n, vector<int>(m, 0)), B(n, vector<int>(m, 0));

    A = {{1, 2},
         {3, 4}};
    B = {{4, 3},
         {2, 1}};

//    IC(n, m, A, B, mod);


    auto At = mat_t(A);
    auto tmp = mul(At, B);
    auto Bt = mat_t(B);
    auto tmp2 = mul(tmp, Bt);
    auto ans_t = mat_t(tmp2);

    int ans_n = ans_t.size();
    int ans_m = ans_t.front().size();

    cout << ans_n << " " << ans_m << endl;
    for (auto &item: ans_t) {
        for (auto &ite: item) {
            cout << ite << " ";
        }
        cout << endl;
    }



//    IC(At);
//
//    IC(mul(A,B));




    return 0;
}