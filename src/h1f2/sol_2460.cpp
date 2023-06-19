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

class Solution {

    // function start.
public:
    vector<int> applyOperations(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        IC(nums);
        int rk = n;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] == 0) {
                std::swap(nums[i], nums[--rk]);
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
    vector<int> nums = {847, 847, 0, 0, 0, 399, 416, 416, 879, 879, 206, 206, 206, 272};
    vector<int> ans = {694, 399, 832, 1758, 412, 206, 272, 0, 0, 0, 0, 0, 0, 0};
    IC(nums, ans);

    IC(solution->applyOperations(nums));

    // code end

    return 0;
}