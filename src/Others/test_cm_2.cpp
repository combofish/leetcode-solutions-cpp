/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <cmath>

class Solution {
public:
    // function start.

    // Input: a 多项式系数，降幂排列
    //      x 估值点
    // Output：多项式在x点的函数值y
    double qinjiushao(vec_t &v, int x) {
        double ret = v.front();
        for (int i = 1; i < v.size(); ++i) {
            ret = ret * x + v[i];
        }
        return ret;
    }
    // function end.
};

int main() {
    using std::pow;
    Solution *solution = new Solution();

    // code start
    vec_t v = {7, 3, -5, 11};
    int x = 23;
    IC(v, x, solution->qinjiushao(v, x));
    IC(7 * pow(x, 3) + 3 * pow(x, 2) - 5 * x + 11);

    vec_t v2 = {1, -18, 144, -672, 2016, -4032, 5376, 4608, 2304, -512};
    int x2 = 2;
    IC(v2, x2, solution->qinjiushao(v2, x2));

    return 0;
}
