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
        int idx = 0;
        for (auto &item: nums)
            if (!item)
                std::swap(item, nums[idx++]);

        for (int i = idx; i < nums.size(); i++)
            if (nums[i] == 1)
                std::swap(nums[i], nums[idx++]);

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


