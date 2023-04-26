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
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix.front().size();
        if (n == 0) return {};

        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;

        vector<int> ans;

        while (top <= bottom && left <= right) {
            for (int i = left; i < right; i++) {
                ans.push_back(matrix[top][i]);
            }

            IC(ans);

            for (int j = top; j <= bottom; j++) {
                ans.push_back(matrix[j][right]);
            }
            IC(ans);

            if (top < bottom && left < right) {
                for (int i = right - 1; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                IC(ans);

                for (int i = bottom - 1; i > top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                IC(ans);
            }
            top++;
            bottom--;
            left++;
            right--;
        }

        return ans;

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    vector<int> ans = {1, 2, 3, 6, 9, 8, 7, 4, 5};

    matrix = {{7},
              {9},
              {6}};
    IC(matrix, ans);
    IC(solution->spiralOrder(matrix));

    // code end

    return 0;
}