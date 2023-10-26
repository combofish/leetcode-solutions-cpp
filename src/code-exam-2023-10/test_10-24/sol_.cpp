#include <bits/stdc++.h>
#include <icecream.hpp>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n , 0));

        for(int i =0; i<n; ++i) dp[i][i] = 1;

        for(int i = n-1; i>=0; --i){
            for(int j = i + 1; j < n; ++j){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }else{
                    dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        IC(dp);
        return dp.back().back();


    }
};
int main(int argc, char const *argv[]) {
    /* code */

    string text1 = "afc", text2 = "abcde"; // afc  abcde

    Solution sol;

    string s = "bbbab";
    int ans = 4;
    IC(s, ans);

    IC(sol.longestPalindromeSubseq(s));

    return 0;
}
