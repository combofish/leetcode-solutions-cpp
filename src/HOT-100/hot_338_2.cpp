/**
-- question:
-- method:
 - [ ] Brian Kernighan 算法
 - [*] 动态规划——最高有效位
 - [ ] 动态规划——最低有效位
 - [ ] 动态规划——最低设置位

--result:

-- analyse:
Time: O( n )
Space: O( 1 )
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <bitset>

class Solution {

    // function start.
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);
        int highBit = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) highBit = i;
            bits[i] = bits[i - highBit] + 1;

            IC(i, highBit, std::bitset<8>(i), bits[i]);
        }
        return bits;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int n = 8;
    vector<int> rel = {0, 1, 1, 2, 1, 2};
    IC(n, rel);

    IC(solution->countBits(n));
    // code end

    return 0;
}
