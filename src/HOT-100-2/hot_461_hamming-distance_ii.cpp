/**
-- question:
-- method:
 - [ ] 内置位计数功能
 - [-] 移位实现位计数
 - [*] Brian Kernighan 算法

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
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    int x = 1, y = 4;
    int ans = 2;

    IC(x, y, ans);

    IC(solution->hammingDistance(x, y));
    // code end

    return 0;
}


