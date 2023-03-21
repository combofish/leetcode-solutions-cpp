/**
-- question: 寻找重复数
-- method:
 - [ ] 二分查找
 - [ ] 二进制
 - [*] 快慢指针, 环

--result:

-- analyse:
Time: O( n )
Space: O( 1 )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int findDuplicate(vector<int> &nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
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


