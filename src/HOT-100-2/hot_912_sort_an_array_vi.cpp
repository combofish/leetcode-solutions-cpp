/**
-- question: 排序数组
-- method:
 - [ ] sort
 - [ ] 冒泡排序 overtime
 - [*] 快速排序
 - [ ] 堆排序
 - [ ] 归并排序

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
    vector<int> sortArray(vector<int> &nums) {
        srand((unsigned) time(nullptr));
        randomized_quicksort(nums, 0, nums.size() - 1);
        return nums;
    }

private:

    void randomized_quicksort(vector<int> &nums, int l, int r) {
        if (l >= r) return;

        // randomized_partition
        int rand_idx = rand() % (r - l + 1) + l;
        swap(nums[rand_idx], nums[r]);

        auto pivot = nums[r];
        int lk = l - 1;
        int rk = r;

        int i = l;
        while (i < rk) {
            if (nums[i] < pivot) {
                swap(nums[i++], nums[++lk]);
            } else if (nums[i] > pivot) {
                swap(nums[i], nums[--rk]);
            } else { ++i; }
        }

        swap(nums[rk], nums[r]);

        randomized_quicksort(nums, l, lk);
        randomized_quicksort(nums, rk, r);

    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {5, 1, 1, 2, 0, 0};
    vector<int> ans = {0, 0, 1, 1, 2, 5};

    IC(nums, ans);
    IC(solution->sortArray(nums));

    // code end

    return 0;
}


