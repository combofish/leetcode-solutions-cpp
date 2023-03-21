/**
-- question: 最大正方形
-- method:
 - [*] 动态规划

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
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size();
        int n = matrix.front().size();
        if (!m || !n) return 0;
        int result = 0;

        auto dp = vector<vector<int>>(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') continue;

                // '1'
                if (i == 0 || j == 0) dp[i][j] = 1;
                else {
                    dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }

                if (dp[i][j] > result) result = dp[i][j];
            }
        }

        IC(dp);


        return result * result;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    int rel = 4;

    IC(matrix, rel);
    IC(solution->maximalSquare(matrix) == rel);
    // code end

    return 0;
}
