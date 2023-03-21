/**
-- question:
-- method:
 - [*] 中心拓展

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    int countSubstrings(string s) {
        int result = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            result += extend(s, i, i, n);
            result += extend(s, i, i + 1, n);
        }
        return result;
    }

private:

    int extend(string &s, int i, int j, int n) {

        int ans = 0;
        while (i >= 0 && j < n && s[i] == s[j]) {
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
    string s = "aaa";
    int rel = 6;
    IC(s, rel);

    IC(solution->countSubstrings(s) == rel);
    // code end

    return 0;
}


