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
        auto f1 = [](double x) { return std::pow(x, 3) + std::pow(x, 2) + x - 3; };
        auto f2 = [](double x) { return 3 * std::pow(x, 2) + 2 * x + 1; };
        auto f3 = [](double x) { return 6 * x + 2; };

        double x1 = 0;
        int itCount = 0;

        double e0 = x0 - 1;
        double e1 = 0;
        IC(itCount, x0, e0);

        do {

            if (itCount) {
                e0 = e1;
                x0 = x1;
            }

            x1 = x0 - (f1(x0) / f2(x0));
            e1 = x1 - 1;

            itCount++;
            IC(itCount, x0, x1, e1, e1 / std::pow(e0, 2), f3(1) / 2 / f2(1));

        } while (itCount < n);
        return x1;
    }

    // function end.
};

int main() {

    Solution *solution = new Solution();

    // code start

    int n = 7;
    IC(solution->newton(-0.7, n));

    return 0;
}
