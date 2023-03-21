/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"

void Choskey(double a[4][4], double L[4][4], int m, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = j; i < m; i++) {
            if (i == j) {
                double sum = 0;
                for (int k = 0; k < j; k++) {
                    sum = sum + L[j][k] * L[j][k];
                }
                L[i][j] = sqrt(a[i][j] - sum);
            } else {
                double sum = 0;
                for (int k = 0; k < j; k++) {
                    sum = sum + L[i][k] * L[j][k];
                }
                L[i][j] = (a[i][j] - sum) / L[j][j];
            }
        }
    }
}

// 初始化L矩阵
void InitL(double L[4][4], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                L[i][j] = 0;
            }
        }
    }
}

//显示L和LT矩阵
void display(double L[4][4], double LT[4][4], int m, int n) {
    cout << "Choskey分解的L矩阵为：" << endl;
    for (int Li = 0; Li < m; Li++) {
        for (int j = 0; j < n; j++) {
            cout << std::setprecision(8) << std::setw(12) << L[Li][j] << "";
        }
        cout << endl;
    }
    cout << "Choskey分解的LT矩阵为：" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << std::setprecision(8) << std::setw(12) << L[j][i] << "";
            LT[i][j] = L[j][i];
        }
        cout << endl;
    }
}

// Ax=b的解答，A为上三角矩阵
void SolveTwo(double LT[4][4], double answer[4], int m, int n) {
    int j = n - 1;
    for (int s = m - 1; s >= 0; s--) {
        answer[j] = answer[j] / LT[s][j];
        for (int i = s - 1; i >= 0; i--) {
            answer[i] = answer[i] - answer[j] * LT[i][j];
        }
        j--;
    }
    cout << "解答的最终结果X为：" << endl;
    for (int i = 0; i < 4; i++) {
        cout << std::setprecision(8) << std::setw(12) << answer[i] << "    ";
    }
    cout << endl;
}

// Ax=b的解答，A为下三角矩阵
void SolveOne(double L[4][4], double answer[4], int m, int n) {
    int j = 0;
    for (int s = j; s < m; s++) {
        answer[j] = answer[j] / L[s][j];
        for (int i = j + 1; i < m; i++) {
            answer[i] = answer[i] - answer[j] * L[i][j];
        }
        j++;
    }
    cout << "解答的中间结果Y为：" << endl;
    for (int i = 0; i < 4; i++) {
        cout << std::setprecision(8) << std::setw(12) << answer[i] << "    ";
    }
    cout << endl;
}

int main() {
    double a[4][4] = {{7,  1, -5, 1},
                      {1,  9, 2,  7},
                      {-5, 2, 7,  -1},
                      {1,  7, -1, 9}};
    double answer[4] = {13, -9, 6, 0};
    double L[4][4];       // L 矩阵
    double LT[4][4];      // LT矩阵
    InitL(L, 4, 4);       //初始化L矩阵
    Choskey(a, L, 4, 4);  //进行Choskey分解
    display(L, LT, 4, 4); //显示L 和LT
    // L*y=b, LT*x=y
    SolveOne(L, answer, 4, 4);  // 先利用上三角矩阵求解y
    SolveTwo(LT, answer, 4, 4); // 利用下三角矩阵求解x

    return 0;
}
