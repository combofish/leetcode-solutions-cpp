/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"

class Solution {

    // function start.
private:
    int mergeSort(vector<int> &nums, vector<int> &tmp, int l, int r) {
        if (l >= r) return 0;
        auto mid = (l + r) >> 1;
        int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        IC(nums, tmp);


        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                ++i;
                inv_count += (j - (mid + 1));
            } else {
                tmp[pos] = nums[j];
                ++j;
            }
            ++pos;
        }

        for (int k = i; k <= mid; ++k) {
            tmp[pos++] = nums[k];
            inv_count += (j - (mid + 1));
        }
        for (int k = j; k <= r; ++k) {
            tmp[pos++] = nums[k];
        }

        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        IC(inv_count, tmp);
        return inv_count;
    }

public:
    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        vector<int> tmp(n);

        return mergeSort(nums, tmp, 0, n - 1);
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {7, 5, 6, 4};
    int ans = 5;
    IC(nums);
    IC(ans);
    IC(solution->reversePairs(nums));


    // code end

    return 0;
}