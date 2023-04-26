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
    const int mod = 1e9 + 7;

public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;

        return 0;

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int n = 10, ans = 36;
    IC(n, ans);

    IC(solution->cuttingRope(n));
    // code end

    return 0;
}