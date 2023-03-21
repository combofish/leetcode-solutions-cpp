/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <tuple>

class Solution {
public:
    // function start.
    string reverseStr(string s, int k) {
        int n = s.size();
        int cnt = n / k / 2;
        int last_n = n % (2 * k);
        IC(n, cnt, last_n);

        auto rev = [](string &s, int i, int j) {
            string debug = ">>> In rev: ";
            IC(debug, s, i, j);

            for (j--; i < j; i++, j--)
                std::swap(s[i], s[j]);
        };

        if (last_n > 0 && last_n < k)
            std::reverse(s.begin() + cnt * 2 * k, s.end());
	
        if (last_n >= k) cnt++;

        // while (cnt--) {
        //     rev(s, cnt * 2 * k, cnt * 2 * k + k);
        // }

        while (cnt--) {
            IC(s);
            std::reverse(s.begin() + cnt * 2 * k, s.begin() + cnt * 2 * k + k);
        }
        return s;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "abcdefg";
    int k = 2;
    string real = "bacdfeg";
    string res = solution->reverseStr(s, k);
    IC(s, k, real, res, res == real);
    // code end

    delete solution;
    return 0;
}
