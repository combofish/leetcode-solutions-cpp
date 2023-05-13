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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;

        int cnt = 0;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i) {
                ans[top][i] = ++cnt;
            }

            for (int j = top + 1; j <= bottom; ++j) {
                ans[j][right] = ++cnt;
            }

            IC(ans);

            if (left < right) {
                for (int i = right - 1; i >= left; --i) {
                    ans[bottom][i] = ++cnt;
                }
            }

            IC(ans);
            if (top < bottom) {
                for (int i = bottom - 1; i > top; --i) {
                    ans[i][left] = ++cnt;
                }
            }
            IC(ans);

            ++left;
            --right;
            ++top;
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

    int n = 3;
    IC(n, solution->generateMatrix(n));
    // code end

    return 0;
}