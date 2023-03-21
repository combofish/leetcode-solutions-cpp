/**
-- question: 数组中重复的数字
-- method:
 - [ ] 哈希表
 - [*] 原地交换

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
    int findRepeatNumber(vector<int> &nums) {
        int i = 0, n = nums.size();
        while (i < n) {
            int k = nums[i];
            IC(i, nums, k);

            if (i == k) {
                i++;
                continue;
            }

            if (nums[k] == k) return k;
            swap(nums[i], nums[k]);
        }


        return -1;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    int rel = 2;
    int rel_2 = 3;
    IC(nums, rel, rel_2);

    IC(solution->findRepeatNumber(nums));
    IC(nums);

    // code end

    return 0;
}
