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
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        int cnt = 0;

        unordered_map<int, int> umap;
        for (auto n1: nums1)
            for (auto n2: nums2)
                umap[n1 + n2]++;

        for (auto n1: nums3)
            for (auto n2: nums4)
                if (umap.find(0 - n1 - n2) != umap.end())
                    cnt += umap[-n1 - n2];

        return cnt;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vec_t nums1 = {1, 2}, nums2 = {-2, -1}, nums3 = {-1, 2}, nums4 = {0, 2};
    int res = 2;

    IC(nums1, nums2, nums3, nums4, res);
    IC(solution->fourSumCount(nums1, nums2, nums3, nums4));
    // code end

    delete solution;
    return 0;
}
