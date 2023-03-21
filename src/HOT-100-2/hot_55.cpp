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
    bool canJump(vector<int> &nums) {
        int cover = 0;
        int n = nums.size();
        //        for (int i = 0; i < n; i++) {
        for (int i = 0; i <= cover; i++) {

            cover = std::max(cover, i + nums[i]);
            if (cover >= n - 1) return true;
        }


        return false;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {2, 3, 1, 1, 4};
    bool result = true;

    IC(nums, result);

    IC(solution->canJump(nums));
    // code end

    return 0;
}
