/**
-- question:
-- method:
 - [ ] Brian Kernighan 算法
 - [ ] 动态规划——最高有效位
 - [ ] 动态规划——最低有效位
 - [-] 动态规划——最低设置位

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <bitset>

class Solution {

    // function start.
public:

    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i & (i - 1)] + 1;
        }
        return dp;

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    int n = 5;
    // int n = 2;
    vector<int> nums = {0, 1, 1, 2, 1, 2};
    IC(n, nums);

    IC(solution->countBits(n));
    // code end

    return 0;
}
