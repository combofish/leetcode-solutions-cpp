/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
    // function start.
    bool isHappy(int n) {
        unordered_set<int> uset;

        auto getSum = [](int n) {
            int sum = 0;
            while (n) {
                int tmp = n % 10;
                sum += (tmp * tmp);
                n /= 10;
            }
            return sum;
        };

        while (true) {
            n = getSum(n);
            IC(n);
            if (n == 1) {
                return true;
            }
            if (uset.find(n) != uset.end()) {
                return false;
            } else {
                uset.insert(n);
            }
        }

    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    int n = 19;
    IC(n, solution->isHappy(n), true);
    // code end

    delete solution;
    return 0;
}
