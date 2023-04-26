/**
-- question: 4. 寻找两个正序数组的中位数
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
    double getKthElement(const vector<int> &nums1, const vector<int> &nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int idx1 = 0, idx2 = 0;

        while (true) {
            if (idx1 == m) return nums2[idx2 + k - 1];
            if (idx2 == n) return nums1[idx1 + k - 1];
            if (k == 1) return std::min(nums1[idx1], nums2[idx2]);

            int nIdx1 = std::min(idx1 + k / 2 - 1, m - 1);
            int nIdx2 = std::min(idx2 + k / 2 - 1, n - 1);
            int privot1 = nums1[nIdx1];
            int privot2 = nums2[nIdx2];

            if (privot1 <= privot2) {
                k -= nIdx1 - idx1 + 1;
                idx1 = nIdx1 + 1;
            } else {
                k -= nIdx2 - idx2 + 1;
                idx2 = nIdx2 + 1;

            }
        }


    }


public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int tot = nums1.size() + nums2.size();
        if (tot % 2 == 1) {
            return getKthElement(nums1, nums2, (tot + 1) / 2);
        } else {
            return 0.5 * (getKthElement(nums1, nums2, tot / 2) + getKthElement(nums1, nums2, tot / 2 + 1));
        }

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums1 = {1, 2}, nums2 = {3, 4};
    IC(nums1, nums2);

    IC(solution->findMedianSortedArrays(nums1, nums2));

    // code end

    return 0;
}