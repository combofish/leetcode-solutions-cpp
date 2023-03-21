/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
    // function start.
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> uset;
        int n1 = nums1.size(), n2 = nums2.size();

        if (n1 < n2) {
            std::swap(n1, n2);
            std::swap(nums1, nums2);
        }

        for (auto n: nums1)
            uset.insert(n);

        // vec_t res;
        unordered_set<int> res;
        for (auto n: nums2)
            if (uset.find(n) != uset.end())
                // res.emplace_back(n);
                res.insert(n);

        return vector<int>(res.begin(), res.end());
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vec_t nums1 = {4, 9, 5}, nums2 = {9, 4, 9, 8, 4};
    IC(nums1, nums2);

    vec_t res = solution->intersection(nums1, nums2);
    IC(res);

    // code end

    delete solution;
    return 0;
}
