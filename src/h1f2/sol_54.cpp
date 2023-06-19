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
        int m = matrix.size(), n = matrix.front().size();
        vector<int> ans(m * n);
        int cnt = -1;

        int left = 0, top = 0, bottom = m - 1, right = n - 1;

        while (left <= right && top <= bottom) {
            for (int i = left; i < right; ++i)
                ans[++cnt] = matrix[top][i];

            for (int i = top; i <= bottom; ++i)
                ans[++cnt] = matrix[i][right];

            if (left < right && top < bottom) {
                for (int j = right - 1; j >= left; --j)
                    ans[++cnt] = matrix[bottom][j];

                for (int j = bottom - 1; j > top; --j)
                    ans[++cnt] = matrix[j][left];
            }

            ++left;
            ++top;
            --right;
            --bottom;
        }

        return ans;

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<int>> matrix = {{1, 2,  3,  4},
                                  {5, 6,  7,  8},
                                  {9, 10, 11, 12}};
    vector<int> ans = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    IC(matrix, ans);

    IC(solution->spiralOrder(matrix));

    queue<pair<int,int>> qu;
    qu.emplace(1,2);
    IC(qu.front());

    // code end

    return 0;
}