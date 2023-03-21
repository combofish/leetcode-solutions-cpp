/**
-- question: 乘积最大子数组
-- method:
 - [ ] for, for
 - [*] 动态规划
 - [ ] 动态规划， 优化空间

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    int maxProduct(vector<int> &nums) {
        vector<int> maxF(nums), minF(nums);
        for (int i = 1; i < nums.size(); i++) {
            maxF[i] = std::max({nums[i], maxF[i - 1] * nums[i], minF[i - 1] * nums[i]});
            minF[i] = std::min({nums[i], minF[i - 1] * nums[i], maxF[i - 1] * nums[i]});
        }
        return *std::max_element(maxF.begin(), maxF.end());
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


