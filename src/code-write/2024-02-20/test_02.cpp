#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

class Solution {
    inline bool cmp(unordered_map<char, int> &ump, unordered_map<char, int> &pat) {
        for (auto &item: pat) {
            if (ump.count(item.first) && ump[item.first] >= item.second) continue;
            else
                return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {

        unordered_map<char, int> pattern;
        for (auto &c: t) {
            ++pattern[c];
        }

        int rk = -1;
        int min_w = INT_MAX;
        string ans = "";
        IC(pattern);

        unordered_map<char, int> ump;
        for (int i = 0; i < s.size(); ++i) {
            ++ump[s[i]];

            // if(cmp(ump, pat)){

            // }

            IC(ump, pattern, min_w);


            while (rk < i && cmp(ump, pattern)) {
                IC(ump, pattern, min_w);

                if (i - rk < min_w) {
                    min_w = i - rk;
                    ans = s.substr(rk + 1, min_w);
                }

                --ump[s[++rk]];
            }
        }


        return ans;
    }
};

int main(int argc, char const *argv[]) {

    string s = "ADOBECODEBANC", t = "ABC", ans = "BANC";
    IC(s, t, ans);

    Solution sol;
    IC(sol.minWindow(s, t));


    return 0;
}
