/**
-- question: 在排序数组中查找元素的第一个和最后一个位置
-- method:
 - [ ] 二分搜索，搜一遍
 - [*] 二分搜索，搜两遍

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
    vector<int> searchRange(vector<int> &nums, int target) {
        auto lIdx = binarySearch(nums, target, true);
        auto rIdx = binarySearch(nums, target, false) - 1;

        if (lIdx <= rIdx && rIdx < nums.size() && nums[lIdx] == target && nums[rIdx] == target) return {lIdx, rIdx};
        return {-1, -1};
    }

private:
    inline int binarySearch(vector<int> &nums, int target, bool lower) {
        int res = nums.size();
        int l = 0;
        int r = res - 1;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                r = mid - 1;
                res = mid;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 7;
    vector<int> res = {3, 4};
    IC(nums, target, res);

    IC(solution->searchRange(nums, target));

    // code end

    return 0;
}
