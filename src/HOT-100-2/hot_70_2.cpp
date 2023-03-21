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
#include <algorithm>

class Solution {

    // function start.
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        array<int, 2> arr = {1, 2};
        for (int i = 2; i < n; i++) {
            auto tmp = arr.back() + arr.front();
            arr.front() = arr.back();
            arr.back() = tmp;
            IC(arr);
        }
        return arr.back();
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    int n = 3;
    int res = 3;
    IC(n, res);

    IC(solution->climbStairs(n));
    // code end

    return 0;
}
