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
        auto f1 = [](double x) { return std::exp(x) * std::sin(x); };
        auto f2 = [](double x) {
            return std::exp(x) * (std::sin(x) + std::cos(x));
        };

        double x1 = 0;
        int itCount = 0;
        do {
            if (itCount)
                x0 = x1;

            x1 = x0 - (f1(x0) / f2(x0));
            itCount++;
            IC(itCount, x1);

        } while (itCount < n);
        return x1;
    }

    double secantMethod(double x0, double x1, int n) {
        auto f1 = [](double x) { return std::exp(x) * std::sin(x); };

        double x2 = 0;
        int itCount = 0;
        do {
            if (itCount) {
                x0 = x1;
                x1 = x2;
            }
            x2 = x1 - f1(x1) / (f1(x1) - f1(x0) + eps) * (x1 - x0);
            ++itCount;

            IC(itCount, x0, x1, x2);
        } while (itCount < n);
        return x2;
    }

    double eps = 1e-6;
    // function end.
};

int main() {

    Solution *solution = new Solution();

    // code start

    int n = 10;
    IC(solution->newton(-3, n));
    IC(solution->secantMethod(-3, -3.05, n));
    return 0;
}
