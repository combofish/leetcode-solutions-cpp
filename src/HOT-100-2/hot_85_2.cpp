/**
-- question:
-- method:
 - [ ] 使用柱状图的暴力解法
 - [*] 单调栈

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
    int maximalRectangle(vector<vector<char>> &matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix.front().size();
        if (!n) return 0;

        vector<vector<int>> rec(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == '1') rec[i][j] = (j == 0 ? 0 : rec[i][j - 1]) + 1;

        IC(rec);
        int ans = 0;

        for (int j = 0; j < n; j++) {
            vector<int> up(m, 0), down(m, 0);

            stack<int> st;
            for (int i = 0; i < m; i++) {
                while (!st.empty() && rec[st.top()][j] >= rec[i][j]) st.pop();

                up[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }

            //            outStack(st);
            IC(up);

            st = stack<int>();
            for (int i = m - 1; i >= 0; i--) {
                while (!st.empty() && rec[st.top()][j] >= rec[i][j]) st.pop();
                down[i] = st.empty() ? m : st.top();
                st.push(i);

                // IC(down);
                // outStack(st);
            }

            //            outStack(st);
            IC(down);

            vector<int> tmp(m);
            for (int i = 0; i < m; i++)
                tmp[i] = down[i] - up[i] - 1;

            IC(tmp);

            //	    IC();

            for (int i = 0; i < m; i++) {
                auto height = down[i] - up[i] - 1;
                int area = height * rec[i][j];
                // IC(height, area);
                //                outStack(st);

                ans = std::max(ans, area);
            }

            cout << endl;
        }

        return ans;
    }


private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    int ans = 6;

    IC(matrix, ans);

    IC(solution->maximalRectangle(matrix));
    // code end

    return 0;
}
