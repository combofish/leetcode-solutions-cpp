/**
-- question: 二维数组中的查找
-- method:
 - [ ] 遍历
 - [-] 二分查找

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
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (!m) return false;

        int n = matrix.front().size();
        if (!n) return false;

        int i = 0, j = n - 1;

        while (i < m && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) {
                --j;
            } else {
                ++i;
            }
        }

        return false;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<int>> matrix = {
            {1, 4, 7, 11, 15},
            {2, 5, 8, 12, 19},
            {3, 6, 9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}};
    int traget = 5;
    bool rel = true;
    IC(matrix, traget, rel);

    IC(solution->findNumberIn2DArray(matrix, traget));
    // code end

    return 0;
}
