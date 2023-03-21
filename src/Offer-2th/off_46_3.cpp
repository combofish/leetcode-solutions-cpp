/**
-- question: 把数字翻译成字符串
-- method:
 - [ ] backtracking
 - [ ] dp
 - [*] recursive 

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int translateNum(int num) {
        if (!num) return 1;

        auto last = num % 100;
        if (last < 10) return translateNum(num / 10);
        else if (last < 26)
            return translateNum(num / 10) + translateNum(num / 100);
        else
            return translateNum(num / 10);
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int n = 12258;
    int rel = 5;

    IC(n, rel);
    IC(solution->translateNum(n) == rel);
    // code end

    return 0;
}
