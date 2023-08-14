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
private:
    bool check(unordered_map<char,int> &ump, unordered_map<char, int> &ori){
        for(auto &item: ori){
            if(ump[item.first] < item.second) return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {

        unordered_map<char,int> ump, cnt;

        for(const auto &c: t){
            ++ump[c];
        }

        int l = 0, r = -1, n = s.size();
        int ans = INT_MAX, ansL = -1;

        while(r < n){
            if(ump.count(s[++r])){
                ++cnt[s[r]];
            }

            while(check(cnt, ump) && l <= r){

                if(r - l + 1 < ans){
                    ans = r - l + 1;
                    ansL = l;

                    IC(s.substr(ansL, ans));
                }

                if(ump.count(s[l])){
                    --cnt[s[l]];
                }
                ++l;
            }
        }

        return ansL == -1 ? "" : s.substr(ansL, ans);
    }
private:
    // function end.
};

int show_size(int *a){

    return sizeof(a);
}

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "ADOBECODEBANC", t = "ABC", ans = "BANC";
    IC(s, t, ans);

    IC(solution->minWindow(s, t));


    int a[10] = {0};
    IC(sizeof(a));

    IC(show_size(a));



    // code end

    return 0;
}