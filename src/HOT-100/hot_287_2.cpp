/**
-- question: 寻找重复数
-- method:
 - [ ] 二分查找
 - [*] 二进制
 - [ ] 快慢指针, 环

--result:

-- analyse:
Time: O( nlog(n) )
Space: O( 1 )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int findDuplicate(vector<int> &nums) {
        int n = nums.size(), ans = 0;
        int bitMax = 31;
        while (!((n - 1) >> bitMax)) bitMax -= 1;

        for (int bit = 0; bit <= bitMax; bit++) {
            int x = 0;
            int y = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] & (i << bit)) x += 1;
                if (i >= 1 && (i & (1 << bit))) y += 1;
            }

            if (x > y) ans |= 1 << bit;
        }

        return ans;

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 3, 4, 2, 2};
    int rel = 2;

    IC(nums, rel);
    IC(solution->findDuplicate(nums) == rel);
    // code end

    return 0;
}


