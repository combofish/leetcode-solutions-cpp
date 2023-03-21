/**
-- question: 至少有 1 位重复的数字
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <string>

class Solution {

    // function start.
public:
    int numDupDigitsAtMostN(int n) {

        return 0;
    }


private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    int n = 100;
    int res = 10;
    IC(n, res);
    IC(solution->numDupDigitsAtMostN(n));

    // code end

    return 0;
}
