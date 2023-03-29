/**
-- question: 数组中的第K个最大元素
-- method:
 - [-] 基于快速排序的选择方法
 - [ ] 基于堆排序的选择方法

--result:

-- analyse:
Time: O(n)
Space: O(log(n))
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int findKthLargest(vector<int> &nums, int k) {
        // srand((unsigned) time(nullptr));

        // k = nums.size() - k;
        // int l = 0, r = nums.size() - 1;
        // while (l < r) {
        //     int idx = rand() % (r - l + 1) + l;
        //     swap(nums[idx], nums[r]);

        //     int pivot = nums[r];
        //     int lk = l - 1;
        //     for (int i = l; i < r; i++)
        //         if (nums[i] <= pivot)
        //             swap(nums[i], nums[++lk]);

        //     swap(nums[++lk], nums[r]);

        //     // return lk;
        //     if (k == lk) return nums[lk];
        //     else {
        //         if (lk < k)
        //             l = lk + 1;
        //         else
        //             r = lk - 1;
        //     }
        // }

        // return nums[k];

        srand((unsigned) time(nullptr));

        int l = 0, r = nums.size() - 1;
        k = nums.size() - k;
        while (l < r) {
            int idx = rand() % (r - l + 1) + l;
            swap(nums[idx], nums[r]);

            IC(idx, nums[idx], nums);

            auto lk = l - 1;
            auto pivot = nums[r];
            for (int i = l; i < r; i++) {
                if (nums[i] <= pivot) {
                    swap(nums[i], nums[++lk]);
                }
            }

            swap(nums[++lk], nums[r]);
            // lk;


            IC(lk, pivot, nums);
            if (lk == k) return nums[k];
            else if (lk < k) {
                l = lk + 1;
            } else {
                r = lk - 1;
            }
        }

        return nums[k];
    }

private:
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
