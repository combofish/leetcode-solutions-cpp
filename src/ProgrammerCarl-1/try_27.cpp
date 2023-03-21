/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <tuple>

class Solution {
public:
    // function start.
    int removeElement(vector<int> &nums, int val) {
        int lowIdx = 0;
        for (int fastIdx = 0; fastIdx < nums.size(); fastIdx++) {
            if (val != nums[fastIdx]) {
                nums[lowIdx++] = nums[fastIdx];
            }
        }
        return lowIdx;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vec_t nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    IC(nums, val);
    IC(solution->removeElement(nums, val));
    IC(nums);
    // code end

    delete solution;
    return 0;
}
