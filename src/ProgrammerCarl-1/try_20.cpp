/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
    // function start.
    bool isValid(string s) {
        if (s.size()%2 == 1) return false;

        stack<char> sta;
        for (auto c: s) {
            if (c == '[' || c == '(' || c == '{') {
                sta.push(c);
            } else {
                if (sta.empty()) return false;
                char _before = sta.top();
                sta.pop();

                if (_before == '[' && c == ']')
                    continue;

                if (_before == '(' && c == ')')
                    continue;

                if (_before == '{' && c == '}')
                    continue;

                return false;
            }

        }

        return sta.empty();

    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "()[]{}";
    IC(s);
    IC(solution->isValid(s) == true);
    // code end

    delete solution;
    return 0;
}


