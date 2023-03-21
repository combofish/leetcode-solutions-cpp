/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O(m+n)
Space: O(m+n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if (m == 0) {
            if (n % 2) return nums2[n / 2];
            else
                return (nums2[n / 2 - 1] + nums2[n / 2]) / 2.0;
        }
        if (n == 0) {
            if (m % 2) return nums1[m / 2];
            else
                return (nums1[m / 2 - 1] + nums1[m / 2]) * 0.5;
        }

        auto rec = vector<int>(m + n, 0);
        int cnt = 0;
        int i = 0, j = 0;
        while (cnt < (m + n)) {
            if (i == m) {
                while (j != n) {
                    rec[cnt++] = nums2[j++];
                }
                break;
            }

            if (j == n) {
                while (i != m) {
                    rec[cnt++] = nums1[i++];
                }
                break;
            }

            if (nums1[i] < nums2[j]) rec[cnt++] = nums1[i++];
            else
                rec[cnt++] = nums2[j++];
        }

        IC(cnt, rec);


        if (cnt % 2) {
            return rec[cnt / 2];
        } else {
            return (rec[cnt / 2 - 1] + rec[cnt / 2]) * 0.5;
        }
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> nums1 = {1, 2}, nums2 = {3, 4};
    double ans = 2.50000;

    IC(nums1, nums2, ans);
    IC(solution->findMedianSortedArrays(nums1, nums2));
    // code end

    return 0;
}
