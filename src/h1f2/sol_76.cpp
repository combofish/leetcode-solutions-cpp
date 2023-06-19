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
        unordered_map<char,int> ori, ump;
        for(auto &c:t){
            ++ori[c];
        }

        int sn = s.size();
        int tn = t.size();
        if(tn > sn) return "";

        int lk = 0;
        int ansL = -1;
        int len = INT_MAX;
        for(int i = 0; i< sn; ++i){
            if(ori.count(s[i])){
                ++ump[s[i]];
            }

            while(lk <= i && check(ump,  ori)){
                auto tmp_len = i - lk + 1;
                if(tmp_len < len){
                    len = tmp_len;
                    ansL = lk;
                }

                --ump[s[lk]];
                ++lk;
            }
        }

        return ansL == -1? "" : s.substr(ansL, len);

    }
private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "ADOBECODEBANC", t = "ABC", ans = "BANC";
    IC(s, t, ans);

    IC(solution->minWindow(s, t));

    // code end

    return 0;
}