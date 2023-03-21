/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"

class Solution {
public:
    // function start.

    double newton(double x0, int n) {
        double eps = 1e-5;

        auto f1 = [](double x) { return std::pow(x, 3) - std::pow(x, 2) - x - 1; };
        auto f2 = [](double x) { return 3 * std::pow(x, 2) - 2 * x - 1; };

        double x1 = 0;
        int itCount = 0;

        do {
            if (itCount) {
                x0 = x1;
            }

            x1 = x0 - (f1(x0) / f2(x0));

            itCount++;
            IC(itCount, x0, x1, std::abs(x1 - x0));
        } while (std::abs(x1 - x0) > eps);
        return x1;
    }

    double newton2(double x0, int n) {
        double eps = 1e-5;

        auto f1 = [](double x) { return std::exp(-x) - x; };
        auto f2 = [](double x) { return -std::exp(-x) - 1; };

        double x1 = 0;
        int itCount = 0;

        do {
            if (itCount) {
                x0 = x1;
            }

            x1 = x0 - (f1(x0) / f2(x0));

            itCount++;
            IC(itCount, x0, x1, std::abs(x1 - x0));
        } while (std::abs(x1 - x0) > eps);
        return x1;
    }
    // function end.
};

int main() {

    Solution *solution = new Solution();

    // code start

    int n = 100;
    IC(solution->newton(2, n));
    out_line();
    IC(solution->newton2(0.6, n));

    return 0;
}
