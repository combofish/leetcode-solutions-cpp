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
#include <math.h>

using namespace std;

//输出二维数组元素，这个函数是用来显示矩阵，用来调试
void display(double a[9][10], int r_size1, int r_size2) {
    for (int i = 0; i < r_size1; i++) {
        for (int j = 0; j < r_size2; j++) {

            cout << setprecision(8) << setw(12) << a[i][j] << "";
            if (j + 1 == r_size2) {
                cout << endl;
            }
        }
    }
}

// Ax=b的解答，A为上三角矩阵
void SolveOne(double a[9][10], int m, int n) {
    int j = n - 2;
    double answer[9];
    for (int s = m - 1; s >= 0; s--) {
        answer[j] = a[s][n - 1] / a[s][j];
        for (int i = 0; i <= s - 1; i++) {
            a[i][n - 1] = a[i][n - 1] - answer[j] * a[i][j];
        }
        j--;
    }
    cout << "解答的结果为：" << endl;
    for (int i = 0; i < 9; i++) {

        cout << setprecision(8) << setw(12) << answer[i] << "    ";
    }
    cout << endl;
}

// Gauss 消元解法 //先转化为上三角矩阵
void Gauss(double a[9][10], int m, int n) {
    double r[9]; // r为每次的倍数
    int k = 0;
    for (int nowi = 0, nowj = 0; nowi < m - 1 && nowj < n - 1; nowi++, nowj++) {
        // 计算要乘的倍数
        for (int s = nowi; s < m; s++) {
            r[s] = a[s + 1][nowj] / a[nowi][nowj];
        }
        // 每次根据每行的倍数将所有数处理一遍,变成 (1,0，0，0)T
        for (int i = nowi; i < m - 1; i++) {
            for (int j = nowj; j < n; j++) {
                a[i + 1][j] = a[i + 1][j] - r[i] * a[nowi][j];
            }
        }
    }
}

// 发现绝对值最大的元素所在一行和当前的一行做交换
void change(double a[9][10], int m, int n, int nowi, int nowj) {
    int record = nowi; //记录该和哪一行做交换
    bool flag = true;  //标志是否需要做交换
    double max = a[nowi][nowj];
    for (int i = nowi + 1; i < m - 1; i++) {
        if (max < fabs(a[i][nowj])) {
            max = a[i][nowj];
            record = i;
            flag = false;
        }
    }
    //行与行之间交换
    if (flag == false) {
        for (int j = nowj; j < n; j++) {
            double s;
            s = a[nowi][j];
            a[nowi][j] = a[record][j];
            a[record][j] = s;
        }
    }
}

//列主元消元解法,转化为上三角矩阵
void Lie(double a[9][10], int m, int n) {
    double r[9]; // r为每次的倍数
    int k = 0;
    for (int nowi = 0, nowj = 0; nowi < m - 1 && nowj < n - 1; nowi++, nowj++) {
        //与Guass不同的时，每次要检查是否需要交换行
        change(a, 9, 10, nowi, nowj);
        // 计算要乘的倍数
        for (int s = nowi; s < m; s++) {
            r[s] = a[s + 1][nowj] / a[nowi][nowj];
        }
        // 每次根据每行的倍数将所有数处理一遍,变成 (1,0，0，0)T
        for (int i = nowi; i < m - 1; i++) {
            for (int j = nowj; j < n; j++) {
                a[i + 1][j] = a[i + 1][j] - r[i] * a[nowi][j];
            }
        }
    }
}

int main() {
    // Gauss 消元
    double a[9][10] = {{31,  -13, 0,   0,   0,   -10, 0,   0,  0,  -15},
                       {-13, 35,  -9,  0,   -11, 0,   0,   0,  0,  -27},
                       {0,   -9,  31,  -10, 0,   0,   0,   0,  0,  -23},
                       {0,   0,   -10, 79,  -30, 0,   0,   0,  -9, 0},
                       {0,   0,   0,   -30, 57,  -7,  0,   -5, 0,  -20},
                       {0,   0,   0,   0,   -7,  47,  -30, 0,  0,  12},
                       {0,   0,   0,   0,   0,   -30, 41,  0,  0,  -7},
                       {0,   0,   0,   0,   -5,  0,   0,   27, -2, 7},
                       {0,   0,   0,   -9,  0,   0,   0,   -2, 29, 10}};
    Gauss(a, 9, 10); //高斯消元
    cout << "Gauss消元的上三角矩阵为" << endl;
    display(a, 9, 10);  //显示矩阵
    SolveOne(a, 9, 10); //求解Ax=b，A为上三角矩阵
    //列主元消元
    double b[9][10] = {{31,  -13, 0,   0,   0,   -10, 0,   0,  0,  -15},
                       {-13, 35,  -9,  0,   -11, 0,   0,   0,  0,  -27},
                       {0,   -9,  31,  -10, 0,   0,   0,   0,  0,  -23},
                       {0,   0,   -10, 79,  -30, 0,   0,   0,  -9, 0},
                       {0,   0,   0,   -30, 57,  -7,  0,   -5, 0,  -20},
                       {0,   0,   0,   0,   -7,  47,  -30, 0,  0,  12},
                       {0,   0,   0,   0,   0,   -30, 41,  0,  0,  -7},
                       {0,   0,   0,   0,   -5,  0,   0,   27, -2, 7},
                       {0,   0,   0,   -9,  0,   0,   0,   -2, 29, 10}};
    Lie(b, 9, 10); //列主元消元
    cout << "列主元消元的上三角矩阵为" << endl;
    display(b, 9, 10);  //显示
    SolveOne(b, 9, 10); //求解Ax=b, A为上三角矩阵
    return 0;
}
