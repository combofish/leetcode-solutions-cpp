/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
private:

    // function start.
public:
    int findMaxForm(vector<string> &strs, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const string &str: strs) {
            int rec[2] = {0};
            for (auto c: str)
                rec[c - '0']++;

            IC(rec);
            for (int i = m; i >= rec[0]; i--) {
                for (int j = n; j >= rec[1]; j--)
                    dp[i][j] = std::max(dp[i][j], dp[i - rec[0]][j - rec[1]] + 1);

                IC(dp);
            }
        }


        return dp.back().back();

    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3, rel = 4;
    IC(strs, m, n, rel);

    IC(solution->findMaxForm(strs, m, n) == rel);


    vector<string> strs_2 = {"10", "0001", "111001", "1", "0"};
    int m_2 = 4;
    int n_2 = 3;
    int rel_2 = 3;
    IC(strs_2, m_2, n_2, rel_2);

    IC(solution->findMaxForm(strs_2, m_2, n_2) == rel_2);

    // code end

    delete solution;
    return 0;
}