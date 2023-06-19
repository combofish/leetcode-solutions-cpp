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
    int equalPairs(vector<vector<int>> &grid) {
        int n = grid.size();

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            auto &curr_line = grid[i];
            for (int j = 0; j < n; ++j) {

                bool isSame = true;
                int k = 0;
                while (k < n && isSame) {
                    if (curr_line[k] != grid[k][j]) {
                        isSame = false;
                        break;
                    }
                    ++k;
                }
                if (isSame) ++ans;
            }
        }
        return ans;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<int>> grid = {{3, 1, 2, 2},
                                {1, 4, 4, 5},
                                {2, 4, 2, 2},
                                {2, 4, 2, 2}};
    int ans = 3;

    IC(grid, ans);

    IC(solution->equalPairs(grid));
    // code end

    return 0;
}