/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"

class Solution {

    // function start.
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // IC(dp[i][j]);
                if (matrix[i][j] == '0') continue;

                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }

                ans = std::max(ans, dp[i][j]);
            }
        }

        IC(dp);
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
    IC(matrix);
    IC(solution->maximalSquare(matrix));

    // code end

    return 0;
}