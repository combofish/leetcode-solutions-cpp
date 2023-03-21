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
        for(auto c: s){
            if (c == '(') {
                sta.push(')');
            }else if (c == '['){
                sta.push(']');
            }else if (c == '{'){
                sta.push('}');
            }else if (sta.empty() || sta.top() != c){
                return false;
            }else{
                sta.pop();
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


