/**
-- question: 阶乘后的零
-- method:
 - [ ] 数学
 - [-] 优化计算

--result:

-- analyse:
Time: O( log n )
Space: O( 1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    int trailingZeroes(int n) {
        int cnt = 0;
        while (n) {
            n /= 5;
            cnt += n;
        }
        return cnt;

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
//    int n = 5;
//    int ans = 1;

    int n = 30;
    int ans = 7;
    IC(n, ans);

    IC(solution->trailingZeroes(n));

    // code end

    return 0;
}


