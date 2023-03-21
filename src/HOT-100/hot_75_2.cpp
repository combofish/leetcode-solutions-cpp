/**
-- question: 颜色分类
-- methods:
 - [ ] 单指针
 - [ ] 双指针 0, 2
 - [*] 双指针 0, 1

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    void sortColors(vector<int> &nums) {
        int idx0 = 0, idx2 = nums.size() - 1;

        for (int i = 0; i <= idx2; i++) {
            while (i <= idx2 && nums[i] == 2) {
                std::swap(nums[i], nums[idx2--]);
            }

            if (nums[i] == 0) std::swap(nums[i], nums[idx0++]);
        }

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    vector<int> rel = {0, 0, 1, 1, 2, 2};
    IC(nums, rel);

    solution->sortColors(nums);
    IC(nums);
    // code end

    return 0;
}


