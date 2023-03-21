/**
-- method: for, for

--result: overtime

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
    // function start.
    int smallestDistancePair(vector<int> &nums, int k) {
        int n = nums.size();

        vec_t rec;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; ++j) {
                rec.emplace_back(std::abs(nums[i] - nums[j]));
            }
        }

        std::sort(rec.begin(), rec.end());
        IC(rec);
        IC(rec[k-1]);

    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {1, 6, 1};
    int k = 3;
    int ret = 5;
    IC(nums, k, ret);
    IC(solution->smallestDistancePair(nums, k));
    // code end

    delete solution;
    return 0;
}
