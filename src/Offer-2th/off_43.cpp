/**
-- question: 1～n 整数中 1 出现的次数
-- method:
 - [*] 枚举

--result:

-- analyse:
Time: O(logn)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int countDigitOne(int n) {
        // mulk 表示 10^k
        // 在下面的代码中，可以发现 k 并没有被直接使用到（都是使用 10^k）
        // 但为了让代码看起来更加直观，这里保留了 k

        long long mulk = 1;
        int ans = 0;
        for (int k = 0; n >= mulk; ++k) {
            long long _a = (n / (mulk * 10)) * mulk;
            long long _b = n % (mulk * 10) - mulk + 1;
            long long _c = std::max(_b, 0LL);
            long long _d = std::min(_c, mulk);
            auto _e = _a + _d;
            IC(_a, _b, _c, _d, _e, mulk);

            ans += (n / (mulk * 10)) * mulk + std::min(std::max(n % (mulk * 10) - mulk + 1, 0LL), mulk);
            mulk *= 10;
            // IC(mulk);
        }
        return ans;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    int n = 100;
    vector<int> rel = {1, 10, 11, 12};
    int res = 5;
    IC(n, rel, res);
    IC(solution->countDigitOne(n));

    // code end

    return 0;
}
