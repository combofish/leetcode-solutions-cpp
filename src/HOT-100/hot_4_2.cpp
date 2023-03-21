/**
-- method:

--result:

-- analyse:
Time: O(log(m+n))
Space: O(1)

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    /**
     *
     * @param nums1
     * @param nums2
     * @return
     */
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size() + nums2.size();
        if (n % 2)
            return getKthElement(nums1, nums2, (n + 1) / 2);
        else
            return (getKthElement(nums1, nums2, n / 2) + getKthElement(nums1, nums2, n / 2 + 1)) / 2.0;
    }

private:
    double getKthElement(const vector<int> &nums1, const vector<int> &nums2, int k) {
        IC(k);
        int n1 = nums1.size();
        int n2 = nums2.size();
        int idx1 = 0, idx2 = 0;
        while (true) {
            if (idx1 == n1)
                return nums2[idx2 + k - 1];
            if (idx2 == n2)
                return nums1[idx1 + k - 1];
            if (k == 1)
                return std::min(nums1[idx1], nums2[idx2]);

            int newIndex1 = std::min(idx1 + k / 2 - 1, n1 - 1);
            int newIndex2 = std::min(idx2 + k / 2 - 1, n2 - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - idx1 + 1;
                idx1 = newIndex1 + 1;
            } else {
                k -= newIndex2 - idx2 + 1;
                idx2 = newIndex2 + 1;
            }

            IC(newIndex1, newIndex2);
            IC(idx1, idx2, nums1[idx1], nums2[idx2]);

        }
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums1 = {1, 3, 4, 9}, nums2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double rel = 4.0;
    IC(nums1, nums2, rel);
    IC(solution->findMedianSortedArrays(nums1, nums2) == rel);

    // code end

    delete solution;
    return 0;
}


