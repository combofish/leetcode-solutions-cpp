/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <typeinfo>

class Solution {
public:
    // function start.
    void quicksort(vec_t &nums, int left, int right) {

        if (left > right) return;
        int i, j, t, temp;

        temp = nums[left];
        i = left;
        j = right;

        while (i != j) {
            while (nums[j] >= temp && i < j)
                --j;

            while (nums[i] <= temp && i < j)
                ++i;

            if (i < j) {
                t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }
        }

        nums[left] = nums[i];
        nums[i] = temp;

        quicksort(nums, left, i - 1);
        quicksort(nums, i + 1, right);
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vec_t nums = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    IC(nums);
    solution->quicksort(nums, 0, nums.size() - 1);
    IC(nums);

    // code end

    delete solution;
    return 0;
}
