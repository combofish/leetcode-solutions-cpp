/**
-- question: 最大矩形
-- method:
 - [ ] 使用柱状图的优化暴力方法
 - [ ] 单调栈

--result:

-- analyse:
Time: O(mn)
Space: O(mn)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        if (!m || !n) return 0;
        auto left = vector<vector<int>>(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
            }
        }

        IC(left);

        int result = 0;
        for (int j = 0; j < n; j++) {
            auto up = vector<int>(m, 0);
            auto down = vector<int>(m, 0);

            auto st = stack<int>();
            for (int i = 0; i < m; i++) {
                while (!st.empty() && left[st.top()][j] >= left[i][j]) st.pop();
                up[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }

            IC(up);

            st = stack<int>();
            for (int i = m - 1; i >= 0; i--) {
                while (!st.empty() && left[st.top()][j] >= left[i][j]) st.pop();
                down[i] = st.empty() ? m : st.top();
                st.push(i);
            }

            IC(j, up, down);

            for (int i = 0; i < m; i++) {
                int height = down[i] - up[i] - 1;
                IC(i, j, height);


                int area = height * left[i][j];
                result = std::max(result, area);
            }
        }

        IC(result);
        return result;

        /**
         * 
                ic| left: [
                [1, 0, 1, 0, 0],
                [1, 0, 1, 2, 3],
                [1, 2, 3, 4, 5],
                [1, 0, 0, 1, 0]
                ]
         * 
         */
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
