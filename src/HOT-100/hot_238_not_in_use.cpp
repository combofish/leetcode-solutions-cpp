/**
-- question: 除自身以外数组的乘积
-- method:
 - [ ] not_in_use： 不让使用除法

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
    vector<int> productExceptSelf(vector<int> &nums) {
        int zeroCount = 0;
        int productNoZero = 1;
        int zeroIndex = -1;
        for (int i = 0; i < nums.size(); i++) {
            int item = nums[i];
            if (item == 0) {
                ++zeroCount;
                zeroIndex = i;
            } else {
                productNoZero *= item;
            }
        }

        vector<int> result(nums.size(), 0);
        if (zeroCount >= 2) return result;
        else if (zeroCount == 1) {
            result[zeroIndex] = productNoZero;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                result[i] = productNoZero / nums[i];
            }
        }

        return result;

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 2, 3, 4};
    vector<int> rel = {24, 12, 8, 6};

    IC(nums, rel);
    IC(solution->productExceptSelf(nums));

    // code end

    return 0;
}


