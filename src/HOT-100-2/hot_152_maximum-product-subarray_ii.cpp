/**
-- question: 乘积最大子数组
-- method:
 - [*] 动态规划 

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <climits>

class Solution {

    // function start.
public:
    int maxProduct(vector<int> &nums) {
        auto maxF = nums.front(), minF = nums.front(), ans = nums.front();

        for (int i = 1; i < nums.size(); i++) {
            auto mx = maxF;
            auto mn = minF;

            maxF = std::max({mx * nums[i], nums[i], nums[i] * mn});
            minF = std::min({mx * nums[i], nums[i], nums[i] * mn});

            ans = std::max(maxF, ans);
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
    int ans = 6;
    IC(nums, ans);

    IC(solution->maxProduct(nums));

    // code end

    return 0;
}
