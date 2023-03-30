/**
-- question: 回文子串
-- method:
 - [-] 中心拓展
 - [ ] Manacher 算法
 - [ ] DP

--result:

-- analyse:
Time: O(n^2)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int countSubstrings(string s) {
        int ans = 0;

        for(int i = 0; i< s.size(); i++){
            ans += expand(s, i, i);
            ans += expand(s, i, i+1);
        }

        return ans;

    }

private:
    int expand(const string s, int i , int j){
        int ans = 0;
        int n = s.size();
        while(i>=0 && j <n && s[i]==s[j]) {
            i--;
            j++;
            ans++;
        }
        return ans;
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "abc";
    int ans = 3;
    IC(s, ans);

    IC(solution->countSubstrings(s));
    // code end

    return 0;
}


