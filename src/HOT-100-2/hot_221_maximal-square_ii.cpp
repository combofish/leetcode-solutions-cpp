/**
-- question:
-- method:
 - [ ] 暴力法
 - [-] 动态规划

--result:

-- analyse:
Time: O( mn )
Space: O( mn )
 */

#include "../combofish_utils.hpp"

// 关键点： 查找最大尺寸

class Solution {

    // function start.
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int n = matrix.size();
        int m = matrix.front().size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') continue;

                IC(i, j);
                // matrix[i][j] == '1'
                if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                ans = std::max(dp[i][j], ans);

                IC(dp, ans);
            }
        }

        return ans * ans;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};

//    matrix = {{'1', '1'},
//              {'1', '1'}};

    int ans = 4;

    IC(matrix, ans);
    IC(solution->maximalSquare(matrix));


    // code end

    return 0;
}
