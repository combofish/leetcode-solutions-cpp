/**
-- method: 两遍扫描

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    void nextPermutation(vector<int> &nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) j--;
            std::swap(nums[i], nums[j]);
        }

        IC(nums);
        std::reverse(nums.begin() + i + 1, nums.end());
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 3, 2}, rel = {2, 1, 3};

    IC(nums, rel);

    solution->nextPermutation(nums);
    IC(nums);
    // code end

    return 0;
}


