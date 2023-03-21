/**
-- question: 二进制中1的个数
-- method:
 - [ ] 循环检查二进制位
 - [*] 位运算优化

--result:

-- analyse:
Time: O(logn)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <fmt/core.h>

class Solution {

    // function start.
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            auto res = fmt::format("{0:b} & {1:b} = {2:b}\n", n, n - 1, n & (n - 1));
            fmt::print(res);

            n &= (n - 1);

            ++cnt;
        }
        return cnt;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int n = 11;
    int rel = 3;
    IC(n, rel);
    IC(solution->hammingWeight(n) == rel);

    // code end

    return 0;
}
