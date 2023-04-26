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
    string longestPalindrome(string s) {

    }


private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "babad";
    string ans = "bab";

    IC(s, ans);

    IC(solution->longestPalindrome(s));

    // code end

    return 0;
}