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
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        // i,j,k,l
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0 && nums[i] > target) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (nums[i] + nums[j] > target && nums[i] + nums[j] > 0) break;


                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    long n = nums[i] + nums[j] + nums[left] + nums[right];
                    if (n < target) left++;
                    else if (n > target) {
                        right--;
                    } else {
                        res.push_back(vector<int>{nums[i], nums[j], nums[right], nums[left]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }
                }
            }
        }

        return res;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vec_t nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    mat_t res = {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};

    IC(nums, target, res);
    IC(solution->fourSum(nums, target));


    // code end

    delete solution;
    return 0;
}
