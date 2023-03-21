/**
-- question: 最大矩形
-- method:
 - [*] 使用柱状图的优化暴力方法
 - [ ] 单调栈

--result:

-- analyse:
Time: O( m^2n )
Space: O( mn )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        auto m = matrix.size();
        int n = matrix.front().size();
        if (!m || !n) return 0;
        auto left = vector<vector<int>>(m, vector<int>(n));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
            }

        IC(left);

        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') continue;


                int width = left[i][j];
                int area = width;
                for (int k = i - 1; k >= 0; k--) {
                    width = std::min(width, left[k][j]);
                    area = std::max(area, (i - k + 1) * width);
                }
                result = std::max(result, area);
            }
        }


        return result;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    int rel = 6;

    IC(matrix, rel);
    IC(solution->maximalRectangle(matrix) == rel);
    // code end

    return 0;
}
