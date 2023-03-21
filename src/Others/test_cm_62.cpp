/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <fmt/core.h>
#include <fmt/printf.h>

class Solution {
public:
    // function start.
    const double PI = 3.141592653589793238463;

    inline double f1(double t) {
        double y = std::exp(-std::pow(t, 2) / 2);
        return y;
    };

    double f(double x, double det = 1e-6) {
        double ans = 0, i = det;
        while (i <= x) {
            ans += det * (f1(i - det) + f1(i)) / 2;
            i += det;
        }

        return 0.5 + ans / std::sqrt(2 * PI);
    }
    // function end.
};

int main() {

    Solution *solution = new Solution();

    // code start
    for (int k = 1; k <= 30; k++) {
        double x = 0.1 * k;
        double y = solution->f(x);
        fmt::printf("f(%.1f) = %.7f\n", x, y);
    }

    fmt::printf("%.7f\n", 1 / 1e-6);

    return 0;
}
