/**
-- question: 排序数组
-- method:
 - [ ] sort
 - [-] 冒泡排序 overtime
 - [ ] 快速排序
 - [ ] 堆排序
 - [ ] 归并排序

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<int> sortArray(vector<int> &nums) {

        auto n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j]) swap(nums[i], nums[j]);
            }
        }

        return nums;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {5, 1, 1, 2, 0, 0};
    vector<int> ans = {0, 0, 1, 1, 2, 5};

    IC(nums, ans);
    IC(solution->sortArray(nums));

    // code end

    return 0;
}


