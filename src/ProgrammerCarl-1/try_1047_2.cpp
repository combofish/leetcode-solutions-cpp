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
        string res;
        for(char &c: s){
            if(res.empty() || res.back() != c){
                res.push_back(c);
            }else{
                res.pop_back();
            }
        }
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


