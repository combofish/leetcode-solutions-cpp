#include <icecream.hpp>
#include <iostream>
#include <vector>


using namespace std;
class Solution {

    inline int getKElement(const vector<int> &nums1, const vector<int> &nums2, int k) {
        int m = nums1.size(), n = nums2.size();

        int idx1 = 0, idx2 = 0;

        while (true) {
            if (idx1 == m) return nums2[idx2 + k - 1];
            if (idx2 == n) return nums1[idx1 + k - 1];

            if (k == 1) return std::min(nums1[idx1], nums2[idx2]);

            auto n_idx1 = std::min(idx1 + k / 2 - 1, m - 1);
            auto n_idx2 = std::min(idx2 + k / 2 - 1, n - 1);
            if (nums1[n_idx1] <= nums2[n_idx2]) {
                k -= n_idx1 - idx1 + 1;
                idx1 = n_idx1 + 1;
            } else {
                k -= n_idx2 - idx2 + 1;
                idx2 = n_idx2 + 1;
            }
        }
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        auto tot = m + n;

        if (tot % 2 == 1) {
            return getKElement(nums1, nums2, (tot + 1) / 2);
        } else {
            return (getKElement(nums1, nums2, tot / 2) + getKElement(nums1, nums2, tot / 2 + 1)) / 2.;
        }
    }
};

int main(int argc, char const *argv[]) {
    /* code */

    Solution sol;

    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    auto ans = sol.findMedianSortedArrays(nums1, nums2);

    IC(ans);

    return 0;
}
