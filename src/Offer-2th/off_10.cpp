/**
-- question: 斐波那契数列
-- method:
 - [*] 动态规划

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
    int fib(int n) {
        if (n < 2) return n;
        const int mod = 1000000007;
        std::pair<int, int> dp;
        dp.first = 0;
        dp.second = 1;

        for (int i = 1; i < n; i++) {
            int tmp = (dp.second + dp.first) % mod;
            dp.first = dp.second;
            dp.second = tmp;
        }

        return dp.second;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int n = 5;
    int rel = 5;
    IC(n, rel);
    IC(solution->fib(n) == rel);

    for (int i = 0; i < 48; i++) IC(solution->fib(i), i);
    // code end

    return 0;
}
