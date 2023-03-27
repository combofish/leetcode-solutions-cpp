/**
-- question: 阶乘后的零
-- method:
 - [ ] 数学
 - [ ] 优化计算

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    int trailingZeroes(int n) {
        int ans = n;
        while (--n) ans *= n;

        IC(ans);
        auto s = std::to_string(ans);

        ans = 0;
        int rk = s.size() - 1;
        while (s[rk--] == '0') {
            ++ans;
        }

        return ans;
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
    int ans = 1;
    IC(n, ans);

    IC(solution->trailingZeroes(n));

    // code end

    return 0;
}


