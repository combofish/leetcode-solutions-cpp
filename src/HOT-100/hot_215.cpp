/**
-- question: 数组中的第K个最大元素
-- method:
 - [*] 基于快速排序的选择方法
 - [ ] 基于堆排序的选择方法

--result:

-- analyse:
Time: O(n)
Space: O(log(n))
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int findKthLargest(vector<int> &nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }


private:
    inline int randomPartition(vector<int> &nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(nums[i], nums[r]);
        return partition(nums, l, r);
    }

    inline int partition(vector<int> &nums, int l, int r) {
        IC(nums);

        int x = nums[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (nums[j] <= x) {
                swap(nums[++i], nums[j]);
                IC(nums[i], nums[j]);
            }
        }

        IC(nums);
        IC();

        swap(nums[i + 1], nums[r]);
        return i + 1;
    }

    int quickSelect(vector<int> &nums, int l, int r, int idx) {
        int q = randomPartition(nums, l, r);
        if (q == idx) return nums[q];
        else return q < idx ? quickSelect(nums, q + 1, r, idx) : quickSelect(nums, l, q - 1, idx);
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    int rel = 4;
    IC(nums, k, rel);

    IC(solution->findKthLargest(nums, k) == rel);

//    vector<int> test = {20, 1, 2, 13, 9};
//    solution->partition(test, 0, test.size() - 1);

    // code end

    return 0;
}


