/**
-- question: 最大正方形
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        auto result = 0;
        int m = matrix.size();
        int n = matrix.front().size();

        

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') continue;

                int tmp = 2;
                while (vaildSquare(matrix, m, n, i, j, tmp)) {
                    tmp++;
                }
                tmp--;
                if (tmp > result) result = tmp;
            }
        }

        IC(result);
        return result * result;
    }

private:
    const int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

   inline bool vaildSquare(vector<vector<char>> &matrix, int m, int n, int startI, int startJ, int len) {
        // 从左向右， 从上到下搜索
        if (startI + len > m || startJ + len > n) return false;

        for(int i = startI; i<startI + len; i++){
            if(matrix[i][startJ + len -1] != '1') return false; 
        }

        for(int j = startJ; j< startJ + len; j++){
            if(matrix[startI +len-1][j] != '1') return false;
        }

        return true;
    }

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
