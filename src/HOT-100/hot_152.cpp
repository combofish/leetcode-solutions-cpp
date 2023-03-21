/**
-- question: 乘积最大子数组
-- method:
 - [ ] for, for
 - [ ] 动态规划

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

    int maxProduct(vector<int> &nums) {
        int ans = INT_MIN;
        int n = nums.size();

        for (int startIdx = 0; startIdx < n; startIdx++) {
            int tmpProduct = 1;
            for (int j = startIdx; j < n; j++) {
                tmpProduct *= nums[j];
                if (tmpProduct > ans) ans = tmpProduct;
            }
        }

        return ans;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> nums = {2, 3, -2, 4};
    int rel = 6;
    IC(nums, rel);

    IC(solution->maxProduct(nums) == rel);

    // code end

    return 0;
}


