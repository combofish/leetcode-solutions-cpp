/**
-- question: Pow(x, n)
-- method: recursive
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
        return N >= 0 ? quickPow(x, N) : 1.0 / quickPow(x, -N);
    }

private:
    double quickPow(double x, long long n) {
        if (n == 0) return 1.0;

        double y = quickPow(x, n / 2);
        if (n % 2) {
            IC(x * y * y);
            return x * y * y;
        } else {
            IC(y * y);
            return y * y;
        }
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

    IC(solution->myPow(x, n) == rel);

    IC();
    double x2 = 2.0;
    int n2 = -2147483648;
    double rel2 = 0;
//    IC(x2, n2, rel2);
//    IC(solution->myPow(x2, n2));

    // code end

    return 0;
}


