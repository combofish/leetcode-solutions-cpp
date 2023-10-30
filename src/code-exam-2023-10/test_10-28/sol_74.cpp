// #include <bits/stdc++.h>
#include <icecream.hpp>
#include <vector>


using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {

        int m = matrix.size(), n = matrix.front().size();

        for (int i = 0; i < m; ++i) {

            return binary_search(matrix[i].begin(), matrix[i].end(), target);

            // if (matrix[i].front() <= target && target <= matrix[i].back()) {

            //     int lk = 0, rk = n - 1;
            //     while (lk <= rk) {
            //         int mid = ((rk - lk) >> 1) + lk;
            //         IC(lk, rk, mid, matrix[i][mid]);

            //         if (matrix[i][mid] == target) return true;
            //         else if (matrix[i][mid] > target) {
            //             rk = mid - 1;
            //         } else {
            //             lk = mid + 1;
            //         }
            //     }

            //     return false;
            // }
        }

        return false;
    }
};

int main(int argc, char const *argv[]) {

    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 16;
    int ans = 1;

    IC(matrix, target, ans);

    Solution sol;
    IC(sol.searchMatrix(matrix, target));


    return 0;
}
