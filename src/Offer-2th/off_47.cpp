/**
-- question: 礼物的最大价值
-- method:
 - [ ] dp
 - [*] dp, 原地修改

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
    int maxValue(vector<vector<int>> &grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid.front().size();
        if (!n) return 0;

        for (int j = 1; j < n; j++) {
            grid.front()[j] += grid.front()[j - 1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (j == 0) grid[i][j] += grid[i - 1][j];
                else
                    grid[i][j] += std::max(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid.back().back();
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<int>> data = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}};
    int rel = 12;
    IC(data, rel);
    IC(solution->maxValue(data) == rel);

    //    int **p = new int[10][10];
    //    int *p[20] = new int[10][10];
    //    int(*p)[20];
    //    int **p;
    //	  int *p[20];
    //    p = new int[10][10];

    // code end

    return 0;
}
