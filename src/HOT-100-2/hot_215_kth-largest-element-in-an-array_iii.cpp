/**
-- question: 数组中的第K个最大元素
-- method:
 - [ ] 基于快速排序的选择方法
 - [-] 基于堆排序的选择方法

--result:

-- analyse:
Time: O(nlog(n))
Space: O(log(n))
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int findKthLargest(vector<int> &nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);

        IC(nums);

        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);

            IC(nums);
        }
        return nums.front();
    }

private:
    void maxHeapify(vector<int> &nums, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && nums[l] > nums[largest]) largest = l;

        if (r < heapSize && nums[r] > nums[largest]) largest = r;
        if (largest != i) {
            swap(nums[i], nums[largest]);
            maxHeapify(nums, largest, heapSize);
        }

    }

    void buildMaxHeap(vector<int> &nums, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i)
            maxHeapify(nums, i, heapSize);
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;

    int ans = 4;

    IC(nums, k, ans);

    IC(solution->findKthLargest(nums, k));
    // code end

    return 0;
}
