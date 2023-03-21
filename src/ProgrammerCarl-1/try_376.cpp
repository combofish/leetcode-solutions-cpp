/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
private:

    // function start.
public:
    int wiggleMaxLength(vector<int> &nums) {
        int result = 1;
        int pre_dif = 0;
        int cur_dif = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            cur_dif = nums[i + 1] - nums[i];
            if ((cur_dif > 0 && pre_dif <= 0) || (cur_dif < 0 && pre_dif >= 0)) {
                result++;
                pre_dif = cur_dif;
            }

        }

        return result;
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    int rel = 7;

    IC(nums, rel);
    IC(solution->wiggleMaxLength(nums));
    // code end

    delete solution;
    return 0;
}


