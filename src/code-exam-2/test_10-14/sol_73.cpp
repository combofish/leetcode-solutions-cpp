#include <bits/stdc++.h>
#include <icecream.hpp>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        unordered_set<int> uet_row, uet_col;

        int m = matrix.size();
        int n = matrix.front().size();

        for (int i = 0; i < m; ++i) {
            if (uet_row.count(i)) continue;

            for (int j = 0; j < n; ++j) {
                if (uet_col.count(j)) continue;


                if (matrix[i][j] == 0) {
                    IC(i, j);


                    for (int col = 0; col < n; ++col) matrix[i][col] = 0;

                    for (int row = 0; row < m; ++row) matrix[row][j] = 0;

                    uet_col.insert(j);
                    uet_row.insert(i);
                }

                break;
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    /* code */
    Solution sol;

    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    decltype(matrix) ans = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};

    IC(matrix, ans);

    sol.setZeroes(matrix);
    IC(matrix);

    return 0;
}
