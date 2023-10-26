#include <icecream.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline bool isMatch(const string &s, const string &p) {
    int m = s.size(), n = p.size();

    auto matches = [&](int i, int j) {
        if (i == 0) return false;
        if (p[j - 1] == '?') return true;
        return s[i - 1] == p[j - 1];
    };

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp.front().front() = 1;

    for (int i = 0; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[i][j] |= dp[i][j - 1];
                if (matches(i, j - 1)) {
                    dp[i][j] |= dp[i - 1][j];
                }
            } else {
                if (matches(i, j)) {
                    dp[i][j] |= dp[i - 1][j - 1];
                }
            }
        }
    }

    IC(s, p);
    IC(m, n);
    IC(dp);

    return dp.back().back();
}

// bool isMatch2(const string &s, const string &p){
//     int m = s.size() + 1, n = p.size() + 1;
//     vector<vector<bool>> dp(m, vector<bool>(n, false));
//     dp.front().front() = true;

//     for(int j = 2; j < n; j+=2){
//         dp[0][j] = dp[0][j-2] && p[j-1] == '*';
//     }

//     for(int i = 1; i<m; ++i){
//         for(int j = 1; j< n; ++j){
//             if(p[j-1] == '*'){
//                 if(dp[i][j-2]) dp[i][j] = true;
//                 else if(dp[i-1][j] && s[i-1] == p[j-2]) dp[i][j] = true;
//                 else if(dp[i-1][j] && p[j-2] == '?') dp[i][j] = true;
//             }else{
//                 if(dp[i-1][j-1] && s[i-1] == p[j-1]) dp[i][j] = true;
//                 else if(dp[i-1][j-1] && p[j-1] == '?') dp[i][j] = true;
//             }
//         }
//     }

//     IC(dp);
//     return dp.back().back();
// }
int main() {
    // int a, b;
    // while (cin >> a >> b) { // 注意 while 处理多个 case
    //     cout << a + b << endl;
    // }


    string findStr, fileName;
    // cin >> findStr;
    // cin >> fileName;

    findStr = "?ef*";
    fileName = "defgh";


    auto ans = isMatch(fileName, findStr);
    //auto ans = isMatch2(fileName, findStr);

    string res = ans ? "true" : "false";
    cout << res << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")