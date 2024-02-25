#include <bits/stdc++.h>
#include <icecream.hpp>
#include <queue>

using namespace std;

class Solution {
    pair<int, int> expand(const string &s, int i, int j) {
        int n = s.size();

        while (i >= 0 && j < n && s[i] == s[j]) {
            --i;
            ++j;
        }

        return {++i, --j};
    }

public:
    string longestPalindrome(string s) {


        int n = s.size();
        // pair<int,int> ans;
        int ans = 0;
        int len = 0;

        for (int i = 0; i < n; ++i) {
            auto a = expand(s, i, i);
            auto b = expand(s, i, i + 1);


            if (a.second - a.first > len) {
                ans = a.first;
                len = a.second - a.first;
            }
            if (b.second - b.first > len) {
                ans = b.first;
                len = b.second - b.first;
            }

            IC(a, b, ans, len);
        }

        return s.substr(ans, len + 1);
    }
};
int main(int argc, char const *argv[]) {


    string s = "cbbd";
    string ans = "bb";
    IC(s, ans);

    Solution sol;
    IC(sol.longestPalindrome(s));

    return 0;
}
