/**
-- question: Pow(x, n)
-- method: iterate
 - []

--result:

-- analyse:
Time: O( log(n) )
Space: O( log(n) )
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    double myPow(double x, int n) {
        long long N = n;
        return (N >= 0) ? quickMul(x, N) : quickMul(x, -N);
    }

private:
    double quickMul(double x, long long n) {
        double ans = 1.0;
        double xContribute = x;
        while (n > 0) {
            if (n % 2) {
                ans *= xContribute;
            }
            xContribute *= xContribute;
            n /= 2;

            IC(ans, xContribute);
        }
        return ans;

    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    double x = 2.0000;
    int n = 11;
    double rel = 2048.0000;
    IC(x, n, rel);

//    IC(solution->myPow(x, n) == rel);

    IC();
    double x2 = 2.0;
    int n2 = 3;
    double rel2 = 8.0;
    IC(x2, n2, rel2);
    IC(solution->myPow(x2, n2));

    // code end

    return 0;
}


