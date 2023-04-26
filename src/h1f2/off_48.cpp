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
    bool is_substr(unordered_map<char,int> &ump){
        IC(ump);
        for(auto &item: ump){
            if (item.second > 1 ) return false;
        }
        return true;
    }

    // function start.
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ump;
        int n = s.size();

        int ans = 0;
        int lk = 0;

        for (int i = 0; i < n; i++) {
            ++ump[s[i]];
            while (!is_substr(ump) && lk <= i) {
                --ump[s[lk]];
                lk++;
            }

            ans = std::max(ans, (int) ump.size());
        }

        return ans;

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "pwwkew";
    int ans = 3;

    IC(s, ans);
    IC(solution->lengthOfLongestSubstring(s));

    // code end

    return 0;
}