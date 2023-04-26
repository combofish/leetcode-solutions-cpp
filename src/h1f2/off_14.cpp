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
    const int mod = 1e9+7;
    // function start.
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        int q = n / 3;
        int t = n % 3;
        if (t == 0) return (int)std::pow(3, q) % mod;
        else if (t == 1) return (int)(std::pow(3, q - 1) * 4) % mod;
        else return (int)(std::pow(3, q) * 2) % mod;
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