/**
-- method:

--result:

-- analyse:
Time: O(n)
Space: O(1)

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
private:

    // function start.
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int n_1 = 1;
        int n_2 = 0;
        for (int i = 2; i <= n; i++) {
            int tmp = n_2 + n_1;
            n_2 = n_1;
            n_1 = tmp;
        }

        return n_1;

    }

    int fib_2(int n) {
        if (n <= 1) return n;
        return fib_2(n - 1) + fib_2(n - 2);
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    int n = 4;
    int rel = 3;
    IC(n, rel);
    IC(solution->fib(n));
    IC(solution->fib_2(n));
    // code end

    delete solution;
    return 0;
}


