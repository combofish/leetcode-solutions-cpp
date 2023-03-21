/**
-- question: 旋转图像

-- method:
- [ ] 使用辅助数组
- [ ] 原地旋转
- [*] 用翻转代替旋转

--result:

-- analyse:
Time: O(N^2)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n; j++) {
                std::swap(matrix.at(i).at(j), matrix[n - i - 1][j]);
            }
        }

        IC(matrix);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<int>> matrix = {{5, 1, 9, 11},
                                  {2, 4, 8, 10},
                                  {13, 3, 6, 7},
                                  {15, 14, 12, 16}};
    vector<vector<int>> rel = {{15, 13, 2, 5},
                               {14, 3, 4, 1},
                               {12, 6, 8, 9},
                               {16, 7, 10, 11}};
    IC(matrix, rel);
    solution->rotate(matrix);
    IC(matrix);
    // code end

    return 0;
}
