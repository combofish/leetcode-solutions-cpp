/**
-- question: 寻找重复数
-- method:
 - [ ] 二分查找
 - [ ] 二进制
 - [*] 快慢指针, 环

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

        int n = nums.size();
        int l = 1, r = n - 1, ans = -1;

        while (l <= r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (const auto &item: nums)
                cnt += item <= mid;

            IC(l, r, mid, cnt);

            if (cnt <= mid) l = mid + 1;
            else {
                r = mid - 1;
                ans = mid;
            }
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


