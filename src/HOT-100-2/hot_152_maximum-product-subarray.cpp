/**
-- question: 乘积最大子数组
-- method:
 - [*] 动态规划 

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <climits>

class Solution {

    // function start.
public:
    int maxProduct(vector<int> &nums) {

        vector<int> maxF(nums), minF(nums);
        for (int i = 1; i < nums.size(); ++i) {
            maxF[i] = std::max({maxF[i - 1] * nums[i], nums[i], minF[i - 1] * nums[i]});
            minF[i] = std::min({maxF[i - 1] * nums[i], nums[i], minF[i - 1] * nums[i]});
        }

        IC(maxF, minF);

        return *std::max_element(maxF.cbegin(), maxF.cend());
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {2, 3, -2, 4};
    int ans = 6;
    IC(nums, ans);

    IC(solution->maxProduct(nums));

    // code end

    return 0;
}
