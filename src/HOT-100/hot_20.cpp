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

    // function start.
public:

    bool isValid(string s) {
        /**
         * cut off
         */
         if(s.size()%2) return false;

        stack<char> st;
        for(auto c: s){
            if(c == '('){
                st.push(')');
            } else if(c == '{'){
                st.push('}');
            }else if(c == '['){
                st.push(']');
            }else{
                if(st.empty() || st.top() != c){
                    return false;
                }else{
                    st.pop();
                }
            }
        }

        return st.empty();
    }
private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "()[]{}";
    bool rel= true;
    IC(s, rel);
    IC(solution->isValid(s) == rel);


    // code end

    delete solution;
    return 0;
}


