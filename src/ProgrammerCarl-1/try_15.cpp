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
    vector<vector<int>> threeSum(vector<int> &nums) {
        mat_t result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            unordered_set<int> uset;
            for (int j = i + 1; j < nums.size(); j++) {

                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) continue;

                int c = 0 - nums[i] - nums[j];
                if (uset.find(c) != uset.end()) {
                    result.push_back({nums[i], nums[j], c});
                    uset.erase(c);
                } else {
                    uset.insert(nums[j]);
                }
            }
        }

        return result;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vec_t nums = {-1, 0, 1, 2, -1, -4};
    IC(nums);
    IC(solution->threeSum(nums));
    // code end

    delete solution;
    return 0;
}
