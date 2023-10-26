#include <bits/stdc++.h>
#include <icecream.hpp>
using namespace std;

int main(int argc, char const *argv[]) {
    /* code */

    string text1 = "afc", text2 = "abcde"; // afc  abcde

    int m = text1.size(), n = text2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int j = 0; j <= n; ++j) dp[0][j] = j;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + 1; // abc  ab(c)
                dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i-1][j-1]}) + 1; // abc  ab(c)
                // afc
            }
        }
    }

    cout << dp.back().back() << endl;
    IC(dp);


    return 0;
}
