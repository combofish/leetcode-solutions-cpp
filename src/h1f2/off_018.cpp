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
public:
    bool isPalindrome(string s) {

        int n = s.size();
        int l = 0, r = n - 1;

        while (l < r) {
            while (l < n && !(isalpha(s[l]) || isdigit(s[l]))) {
                ++l;
            }
            while (r >= 0 && !(isalpha(s[r]) || isdigit(s[r]))) {
                --r;
            }

            IC(l, r);
            if (l < r && tolower(s[l]) != tolower(s[r])) return false;
            ++l;
            --r;
        }
        return true;

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "0p";
    bool ans = false;
    IC(s);
    IC(ans);
    IC(solution->isPalindrome(s));
    // code end

    return 0;
}