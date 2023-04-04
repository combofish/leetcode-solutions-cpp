/**
-- question:
-- method:
 - [-] 暴力法
 - [ ] 动态规划

--result:

-- analyse:
Time: O( mn * min(m,n)^2 )
Space: O(1)
 */

#include "../combofish_utils.hpp"

// 关键点： 查找最大尺寸

class Solution {

    // function start.
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int n = matrix.size();
        int m = matrix.front().size();

        int ans = matrix.front().front() == '1' ? 1 : 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') continue;

                // matrix[i][j] == '1'
                auto tmp_len = ans;
                bool can_use = true;

                while (can_use) {
                    tmp_len++;
//                    IC(i, j, tmp_len);
                    if (i + tmp_len > n || j + tmp_len > m) can_use = false;

                    for (int k = 0; k < tmp_len && can_use; k++) {
                        for (int l = 0; l < tmp_len && can_use; l++) {
                            IC(i + k, j + l);
                            if (matrix[i + k][j + l] != '1') can_use = false;
                        }
                    }
                    IC(i, j, tmp_len, can_use);
                }
                // --tmp_len;
//
//                IC(ans, tmp_len);
                ans = std::max(ans, tmp_len - 1);
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

    matrix = {{'1', '1'},
              {'1', '1'}};

    int ans = 4;

    IC(matrix, ans);
    IC(solution->maximalSquare(matrix));


    // code end

    return 0;
}
