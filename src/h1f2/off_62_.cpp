/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"

class Solution {

    // function start.
public:
    int lastRemaining(int n, int m) {
        if (n == 1) return 0;
        auto x = lastRemaining(n - 1, m);
        IC(n, m, x);
        return (x + m) % n;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    int n = 5, m = 3;
    IC(n, m);
    IC(solution->lastRemaining(n, m));
    // code end

    return 0;
}