/**
-- question: 在排序数组中查找元素的第一个和最后一个位置
-- method:
 - [*] 二分搜索，搜一遍
 - [ ] 二分搜索，搜两遍

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
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (target < nums[mid]) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {

                break;
            }
        }

        if (mid < 0 || mid >= nums.size() || nums[mid] != target) return {-1, -1};

        auto res = vector<int>(2, mid);

        while (res.front() > 0 && nums[res.front() - 1] == target) res.front()--;
        while (res.back() < nums.size() - 1 && nums[res.back() + 1] == target) res.back()++;

        return res;
    }

private:
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
