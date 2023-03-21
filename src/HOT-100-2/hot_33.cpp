/**
-- question:
-- method:
 - []

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
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        if (!n) return -1;
        if (n == 1) return nums.front() == target ? 0 : -1;

        int lk = 0, rk = n - 1;
        while (lk <= rk) {
            auto mid = (lk + rk) >> 1;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[lk] <= nums[mid]) {
                if (target >= nums[lk] && target < nums[mid]) {
                    rk = mid - 1;
                } else {
                    lk = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[rk]) {
                    lk = mid + 1;
                } else {
                    rk = mid - 1;
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
    vector<int> nums = {5, 1, 3};
    int target = 5;
    int res = 0;
    IC(nums, target, res);
    IC(solution->search(nums, target));
    // code end

    return 0;
}
