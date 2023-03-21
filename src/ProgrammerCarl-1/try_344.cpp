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
    void reverseString(vector<char> &s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            std::swap(s[i], s[j]);
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    vector<char> res = {'o', 'l', 'l', 'e', 'h'};
    IC(s, res);
    solution->reverseString(s);
    IC(s, s == res);
    // code end

    delete solution;
    return 0;
}
