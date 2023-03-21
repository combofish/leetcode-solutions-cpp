/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

void out_stack(stack<int> sta){
    vector<int> res;
    while(!sta.empty()){
        res.push_back(sta.top());
        sta.pop();
    }
    std::reverse(res.begin(), res.end());
    IC(res);
}
class Solution {

public:
    // function start.
    int evalRPN(vector<string> &tokens) {
        stack<int> sta;
        for (string &s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int tmp_2 = sta.top();
                sta.pop();

                int tmp_1 = sta.top();
                sta.pop();

                if (s == "+") sta.push(tmp_1 + tmp_2);
                if (s == "-") sta.push(tmp_1 - tmp_2);
                if (s == "*") sta.push(tmp_1 * tmp_2);
                if (s == "/") sta.push(tmp_1 / tmp_2);



            } else {
                sta.push(std::stoi(s));
            }
            out_stack(sta);

        }
        int res = sta.top();

        sta.pop();
        return res;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int rel = 22;

    IC(tokens, rel);
    IC(solution->evalRPN(tokens) == rel);



    vector<string> tokens_2 = {"-128","-128","*","-128","*","-128","*","8","*","-1","*"};
    int rel_2 = -2147483648;

    IC();
    IC(tokens_2, rel_2, solution->evalRPN(tokens_2) == rel_2);
    // code end

    delete solution;
    return 0;
}


