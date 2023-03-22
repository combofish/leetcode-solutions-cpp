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
    int maxSubArray(vector<int> &nums) {
        int pre = nums.front();
        int n = nums.size();

        int ans = pre;

        for (int i = 1; i < n; i++) {
            auto tmp = std::max(nums[i], pre + nums[i]);
            if (tmp > ans) ans = tmp;
            pre = tmp;
        }
        return ans;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = 6;
    IC(nums, ans);


    IC(solution->maxSubArray(nums));
    // code end

    return 0;
}
