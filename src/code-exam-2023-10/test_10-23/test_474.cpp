#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;


class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp.front().front() = 1;

        for (auto &str: strs) {
            int cnt_0 = 0;
            for (auto &c: str)
                if (c == '0') ++cnt_0;
            int cnt_1 = str.size() - cnt_0;

            IC(cnt_0, cnt_1);


            for (int i = m; i >= cnt_0; --i) {
                for (int j = n; j >= cnt_1; --j) {
                    IC(i,j, cnt_0, cnt_1);

                    dp[i][j] = std::max(dp[i][j], dp[i - cnt_0][j - cnt_1] + 1);
                }
            }

            if(str == "0"){
                int a = 1;
                IC(a);
            }

            IC(dp);
        }

        IC(dp);

        return dp.back().back();
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;

    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5;
    int n = 3;

    IC(strs, m, n);
    auto ans = sol.findMaxForm(strs, m, n);
    IC(ans);
    return 0;
}
