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
public:
    // function start.
    int search(vector<int> &nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j) {
            int k = i + (j - i) / 2;
            if (target < nums[k]) {
                j = k - 1;
            } else if (target > nums[k]) {
                i = k + 1;
            } else {
                return k;
            }
        }

        return -1;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start

    vec_t nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    IC(nums, target);
    IC(solution->search(nums, target));

    // code end

    delete solution;
    return 0;
}
