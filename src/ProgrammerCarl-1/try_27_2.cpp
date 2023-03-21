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
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j) {
            while (i <= j && nums[i] != val) ++i;
            while (i <= j && nums[j] == val) --j;

            if (i < j) nums[i++] = nums[j--];
        }

        return i;
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
