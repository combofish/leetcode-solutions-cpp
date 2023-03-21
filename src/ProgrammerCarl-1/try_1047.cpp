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
    string removeDuplicates(string s) {
        stack<char> sta;
        for (auto c: s) {
            if (sta.empty()) {
                sta.push(c);
                continue;
            }

            if (sta.top() == c) {
                sta.pop();
            }else{
                sta.push(c);
            }
        }

        string res;
        while(!sta.empty()){
            res += sta.top();
            sta.pop();
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string input = "abbaca";
    string rel = "ca";
    IC(input, rel);

    IC(solution->removeDuplicates(input) == rel);

    // code end

    delete solution;
    return 0;
}


