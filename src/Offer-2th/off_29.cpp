/**
-- question: 顺时针打印矩阵
 - [ ] 模拟
 - [*] 按层模拟

--result:

-- analyse:
Time: O(mn)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        if (!m || !n) return vector<int>();
        vector<int> result;

        int left = 0, right = n - 1, top = 0, bottom = m - 1;

        while (left <= right && top <= bottom) {
            IC(left, right, top, bottom);

            for (int j = left; j <= right; j++)
                result.emplace_back(matrix[top][j]);

            for (int i = top + 1; i <= bottom; i++)
                result.emplace_back(matrix[i][right]);

            if (left < right && top < bottom) {
                for (int j = right - 1; j >= left; j--)
                    result.emplace_back(matrix[bottom][j]);

                for (int i = bottom - 1; i >= top + 1; i--)
                    result.emplace_back(matrix[i][left]);
            }

            ++left;
            --right;
            ++top;
            --bottom;
        }
        return result;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> rel = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    IC(matrix, rel);
    IC(solution->spiralOrder(matrix));
    // code end

    return 0;
}
