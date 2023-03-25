/**
-- question: 寻找重复数
-- method:
 - [-] 二分查找
 - [ ] 二进制
 - [*] 快慢指针

--result:

-- analyse:
Time: O( nlog(n) )
Space: O( 1 )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

/**
 * 不理解
 */
class Solution {

    // function start.
public:
    int findDuplicate(vector<int> &nums) {
        int n = nums.size();
        int lk = 1, rk = n - 1;
        int ans = -1;

        while (lk <= rk) {
            auto mid = (lk + rk) >> 1;
            int cnt = 0;
            for (auto &num: nums) cnt += num <= mid;

            if (cnt <= mid) lk = mid + 1;
            else {
                rk = mid - 1;
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
    int ans = 2;

    IC(nums, ans);
    IC(solution->findDuplicate(nums));

    // code end

    return 0;
}


