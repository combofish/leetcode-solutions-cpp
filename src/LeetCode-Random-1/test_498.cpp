/**
-- method: for, flag

--result:
 执行用时： 20 ms , 在所有 C++ 提交中击败了 90.04% 的用户
 内存消耗： 17.7 MB , 在所有 C++ 提交中击败了 90.33% 的用户
 通过测试用例： 32 / 32

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>


int dirs1[3][2] = {{-1, 1},
                   {0,  1},
                   {1,  0}};

int dirs2[3][2] = {{1, -1},
                   {1, 0},
                   {0, 1}};

class Solution {
    void nextPoint(int &x, int &y, int m, int n, bool &upFlag) {
        for (int i = 0; i < 3; i++) {
            int new_x, new_y;
            if (upFlag) {
                new_x = x + dirs1[i][0];
                new_y = y + dirs1[i][1];
            } else {
                new_x = x + dirs2[i][0];
                new_y = y + dirs2[i][1];
            }

            IC(new_x, new_y);

            if (new_x < 0 || new_x >= m || new_y >= n || new_y < 0) {
                continue;
            } else {

                if (i != 0) {
                    upFlag = !upFlag;
                }
                x = new_x;
                y = new_y;
                return;
            }
        }
        upFlag = !upFlag;
    }

public:
    // function start.
    vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
        vector<int> ret;

        int m = mat.size(), n = mat[0].size();
        int i = 0, j = 0;
        bool upFlag = true;

        int turns = m + n - 1;

        for (int k = 0; k < turns; ++k) {
            auto curFlag = upFlag;
            while (curFlag == upFlag) {
                IC(ret);

                ret.emplace_back(mat[i][j]);
                nextPoint(i, j, m, n, upFlag);

            }
        }
        return ret;

    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    mat_t mat = {{1, 2, 3},
                 {4, 5, 6},
                 {7, 8, 9}};

    vec_t ret = {1, 2, 4, 7, 5, 3, 6, 8, 9};
    IC(mat);
    IC(solution->findDiagonalOrder(mat));
    IC(ret);

    // code end

    delete solution;
    return 0;
}
