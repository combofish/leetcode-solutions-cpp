/**
-- question: 剑指 Offer 14- II. 剪绳子 II
-- method:
 - [ ] 贪心思想 + 快速幂求余
 - [*] 贪心思想 

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        const int mod = 1000000007;
        long ret = 1;
        int b = n % 3;
        int cnt = n / 3;
        while (--cnt) ret = ret * 3 % mod;

        IC(ret, b, cnt);

        if (b == 1) return ret * 4 % mod;
        else if (!b)
            return ret * 3 % mod;
        else
            return ret * 6 % mod;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    int n = 5;
    int rel = 6;
    IC(n, rel);
    IC(solution->cuttingRope(n));
    // code end

    return 0;
}
