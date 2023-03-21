/**
-- method:

--result:

-- analyse:
Time: O(n)
Space: O(1)

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
private:

    // function start.
public:
    /**
     * greedy
     * @param n
     * @return
     */
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;
        int result = 1;
        while(n>4){
            result *= 3;
            n -=3;
        }

        result *= n;
        return result;
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    int n = 10;
    int rel = 36;
    vector<int> res = {3,3,4};
    IC(n, rel, res);
    IC(solution->integerBreak(n));

    // code end

    delete solution;
    return 0;
}


