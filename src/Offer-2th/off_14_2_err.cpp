/**
-- question: 剑指 Offer 14- II. 剪绳子 II
-- method:
 - [ ] 贪心思想 + 快速幂求余

--result:

-- analyse:
Time: O(logn)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        int a = n / 3 - 1;
        int b = n % 3;
        const int p = 1000000007;
        int x = 3;
        int rem = 1;

        while (a > 0) {
            IC(a, x);

            if (a % 2) rem = (rem * x) % p;
            x = (x * x) % p;
            a /= 2;
        }

        if (b) return (rem * 4) % p;// 3^a*4
        else
            return (rem * 3) % p;// 3^(a+1)

        return (rem * 6) % p;// 3^(a+1) * 2
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
