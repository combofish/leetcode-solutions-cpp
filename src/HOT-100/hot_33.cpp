/**
-- question: 搜索旋转排序数组
-- method:
 - []

--result:

-- analyse:
Time: O( log(n) )
Space: O( 1 )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        if (!n) return -1;
        if (n == 1) return nums.front() == target ? 0 : -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int rel = 4;

    IC(nums, target, rel);
    IC(solution->search(nums, target) == rel);
    // code end

    return 0;
}
