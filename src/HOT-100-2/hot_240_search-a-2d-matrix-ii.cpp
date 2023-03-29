/**
-- question: 搜索二维矩阵 II
-- method:
 - [-] 直接查找
 - [ ] 二分查找
 - [ ] Z 字形查找

--result:

-- analyse:
Time: O(mn)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        for (auto &row: matrix)
            for (auto &n: row)
                if (n == target) return true;

        return false;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<int>> matrix = {{1,  4,  7,  11, 15},
                                  {2,  5,  8,  12, 19},
                                  {3,  6,  9,  16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    int target = 5;
    bool ans = true;

    IC(matrix, target, ans);
    IC(solution->searchMatrix(matrix, target));


    // code end

    return 0;
}


