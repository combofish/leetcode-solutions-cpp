/**
-- method:

--result:

-- analyse:
Time: O(m+n)
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
        int n1 = nums1.size();
        int n2 = nums2.size();

        int n_max = (n1 + n2) / 2 + 1;
        IC(n1, n2, n_max);

        std::pair<int, int> rec(0, 0);
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();

        int i = 0;
        while (i < n_max) {
            rec.first = rec.second;
            if (it1 != nums1.end() && it2 != nums2.end()) {
                if (*it1 < *it2) {
                    rec.second = *it1;
                    it1++;
                } else {
                    rec.second = *it2;
                    it2++;
                }
            } else if (it1 != nums1.end()) {
                rec.second = *it1;
                it1++;
            } else if (it2 != nums2.end()) {
                rec.second = *it2;
                it2++;
            }

            i++;
            IC(rec);
        }


        IC(rec, n_max);

        if ((n1 + n2) % 2) {
            IC('/');
            return rec.second;
        } else {
            IC("/2");
            return 1.0 * (rec.first + rec.second) / 2.0;
        }
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums1 = {1, 3}, nums2 = {2};
    int rel = 2;
    IC(nums1, nums2, rel);
    IC(solution->findMedianSortedArrays(nums1, nums2) == rel);

    // code end

    delete solution;
    return 0;
}


