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
#include <algorithm>

class Solution {

    // function start.
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        int n = matrix.front().size();


        int max_m = m;
        int max_n = n;
        for (int i = 0; i < max_m; i++) {

            int j = 0;
            if (i >= m || matrix[i][j] > target) break;

            while (j < max_n) {
                if (matrix[i][j] == target) return true;
                else if (matrix[i][j] > target) {
                    max_n = j;
                }
                j++;
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
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 5;
    bool rel = true;

    IC(matrix, target, rel);

    IC(solution->searchMatrix(matrix, target));

    // code end

    return 0;
}
