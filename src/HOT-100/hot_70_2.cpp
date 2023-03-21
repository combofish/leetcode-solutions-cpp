/**
-- question: 爬楼梯
-- method: 动态规划

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    int climbStairs(int n) {
        if (n < 3) return n;
        std::array<int, 2> dp{1, 2};
        for (int i = 3; i <= n; i++) {
            int tmp = dp.front() + dp.back();
            dp.front() = dp.back();
            dp.back() = tmp;
        }

        return dp.back();


    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int n = 3, rel = 3;
    IC(n, rel);

    IC(solution->climbStairs(n) == rel);
    // code end

    return 0;
}


