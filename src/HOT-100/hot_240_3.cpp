/**
-- question: 搜索二维矩阵 II
-- method:
 - [ ] 直接查找
 - [ ] 二分查找
 - [*] 方法三：Z 字形查找

--result:

-- analyse:
Time: O(m+n)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        int n = matrix.front().size();

        int i = 0;
        int j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target)
                j--;
            else
                i++;
        }

        return false;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 5;
    bool rel = true;

    IC(matrix, target, rel);

    IC(solution->searchMatrix(matrix, target));

    // code end

    return 0;
}
