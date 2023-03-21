/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <iomanip>
#include <iostream>

using namespace std;

//定义矩阵相乘
void XMatirx(float LL[9][9], float a[9][9], int m, int n) {
    float c[9][9];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            float sum = 0;
            for (int s = 0; s < n; s++) {
                sum = sum + LL[i][s] * a[s][j];
                if (i == 0 && j == 0 && s == 0) {
                    //   cout<<LL[i][s]<<"  "<<a[0][0]<<endl;
                    //    cout<<LL[i][s]*a[s][j]<<endl;
                }
            }
            c[i][j] = sum;
        }
    }
    //写回到B数组中，即为最终的U
    for (int i1 = 0; i1 < m; i1++) {
        for (int j = 0; j < n; j++) {
            a[i1][j] = c[i1][j];
        }
    }
}

//输出二维数组元素，这个函数是用来显示矩阵，用来调试
void display(float a[9][9], int r_size1, int r_size2) {
    for (int i = 0; i < r_size1; i++) {
        for (int j = 0; j < r_size2; j++) {

            cout << setprecision(3) << setw(12) << a[i][j] << "";
            if (j + 1 == r_size2) {
                cout << endl;
            }
        }
    }
}

// LU 分解
void LU(float a[9][9], float L[9][9], int m, int n) {
    float r[9]; // r为每次的倍数
    int k = 0;
    float LL[9][9]; //临时矩阵专门用来存储当前的L1，L2，L3
    //初始化L矩阵
    for (int si = 0; si < m; si++) {
        for (int sj = 0; sj < n; sj++) {
            if (si == sj) {
                L[si][sj] = 1;
            } else {
                L[si][sj] = 0;
            }
        }
    }
    for (int nowi = 0, nowj = 0; nowi < m - 1 && nowj < n - 1; nowi++, nowj++) {
        //初始化LL矩阵
        for (int si = 0; si < m; si++) {
            for (int sj = 0; sj < n; sj++) {
                if (si == sj) {
                    LL[si][sj] = 1;
                } else {
                    LL[si][sj] = 0;
                }
            }
        }
        //   display(LL,9,9);
        // 计算要乘的倍数
        for (int s = nowi; s < m - 1; s++) {
            r[s] = a[s + 1][nowj] / a[nowi][nowj];
            //填充L矩阵
            L[s + 1][nowj] = r[s];
            LL[s + 1][nowj] = -r[s];
        }
        //调用矩阵相乘公式
        XMatirx(LL, a, 9, 9);
    }
}

int main() {
    float a[9][9] = {
            {31,  -13, 0,   0,   0,   -10, 0,   0,  0},
            {-13, 35,  -9,  0,   -11, 0,   0,   0,  0},
            {0,   -9,  31,  -10, 0,   0,   0,   0,  0},
            {0,   0,   -10, 79,  -30, 0,   0,   0,  -9},
            {0,   0,   0,   -30, 57,  -7,  0,   -5, 0},
            {0,   0,   0,   0,   -7,  47,  -30, 0,  0},
            {0,   0,   0,   0,   0,   -30, 41,  0,  0},
            {0,   0,   0,   0,   -5,  0,   0,   27, -2},
            {0,   0,   0,   -9,  0,   0,   0,   -2, 29}};
    float L[9][9];
    LU(a, L, 9, 9); // LU分解
    cout << "LU分解的L矩阵为" << endl;
    display(L, 9, 9);
    cout << "LU分解的U矩阵为" << endl;
    display(a, 9, 9);
    cout << endl;
    return 0;
}
