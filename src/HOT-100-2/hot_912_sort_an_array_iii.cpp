/**
-- question: 排序数组
-- method:
 - [ ] sort
 - [ ] 冒泡排序 overtime
 - [ ] 快速排序
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
        if (l < r) {
            auto pos = randomized_partition(nums, l, r);
            randomized_partition(nums, l, pos - 1);
            randomized_partition(nums, pos + 1, r);
        }
    }

    int randomized_partition(vector<int> &nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(nums[i], nums[r]);
        return partition(nums, l, r);

    }

    int partition(vector<int> &nums, int l, int r) {
        auto pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums[j], nums[i]);
            }

// 重复元素很多的时候会超时


        }

        swap(nums[i + 1], nums[r]);
        return i + 1;
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


