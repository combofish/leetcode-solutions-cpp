/**
-- question:
-- method:
 - [*] 使用柱状图的暴力解法
 - [ ] 单调栈

--result:

-- analyse:
Time: O(m^2n)
Space: O(mn)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix.front().size();
        if (!n) return 0;

        vector<vector<int>> rec(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    rec[i][j] = (j == 0 ? 0 : rec[i][j - 1]) + 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rec[i][j] == 0) continue;

                int width = rec[i][j];
                auto area = width;
                for (int k = i - 1; k >= 0; k--) {
                    width = std::min(width, rec[k][j]);

                    area = std::max(area, width * (i - k + 1));
                }
                ans = std::max(ans, area);
            }
        }

        IC(rec);


        return ans;
    }


private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    //    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};

    vector<vector<char>> matrix = {{'1'}};
    int ans = 6;

    IC(matrix, ans);

    IC(solution->maximalRectangle(matrix));
    // code end

    return 0;
}
