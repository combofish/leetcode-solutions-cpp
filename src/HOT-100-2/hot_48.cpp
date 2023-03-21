/**
-- question:
-- method:
 - [ ] 用翻转代替旋转

--result:

-- analyse:
Time: O(N^2)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <deque>

class Solution {

    // function start.
public:
    void rotate(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = m / 2;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::swap(matrix[i][j], matrix[i][m - j - 1]);
            }
        }
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> result = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};

    IC(matrix, result);

    solution->rotate(matrix);
    IC(matrix);
    // code end

    return 0;
}
