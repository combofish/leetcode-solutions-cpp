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
            if (nums[i] > 0) return result;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int n = nums[left] + nums[right] + nums[i];
                if (n > 0) right--;
                else if (n < 0)
                    left++;
                else {
                    result.push_back({nums[i], nums[right], nums[left]});
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    while (left < right && nums[left] == nums[left + 1]) left++;

                    right--;
                    left++;
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
