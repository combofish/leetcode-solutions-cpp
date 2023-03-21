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
        int idx0 = 0, idx1 = 0;

        for (auto &item: nums) {
            IC(nums);
            if (item == 1) {
                std::swap(item, nums[idx1++]);
            } else if (item == 0) {
//              IC(nums);
                std::swap(item, nums[idx0]);
                if (idx0 < idx1) {

                    IC(nums, idx0, idx1);
                    std::swap(item, nums[idx1]);
                    IC(nums, idx0, idx1);
                }
//             IC(nums);
                ++idx1;
                ++idx0;
            }
        }
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 2, 1, 0, 2};
    vector<int> rel = {0, 1, 1, 2, 2};
    IC(nums, rel);

    solution->sortColors(nums);
    IC(nums);
    // code end

    return 0;
}


