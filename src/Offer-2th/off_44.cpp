/**
-- question: 数字序列中某一位的数字
-- method:
 - [ ] 二分查找
 - [*] 直接计算

--result:

-- analyse:
Time: O(logn)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <icecream.hpp>
#include <string>

class Solution {

    // function start.
public:
    auto findNthDigit(int n) {
        int d = 1, count = 9;
        while (n > (long) d * count) {
            n -= d * count;
            d++;
            count *= 10;

            IC(n, d, count);
        }

        auto idx = n - 1;
        auto low = (int) std::pow(10, d - 1);
        auto num = low + idx / d;
        auto digitIdx = idx % d;
        auto digit = (num / (int) (std::pow(10, d - digitIdx - 1))) % 10;

        IC(std::to_string(num)[digitIdx] - '0');

        IC(idx, low, num, digitIdx, digit);

        return digit;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int n = 11, rel = 0;
    IC(n, rel);

    IC(solution->findNthDigit(n) == rel);//
    //    IC();
    // IC(solution->findNthDigit(9));
    // IC();
    //     IC(solution->findNthDigit(99));
    // code end

    return 0;
}
