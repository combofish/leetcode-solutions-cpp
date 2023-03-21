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

    // function start.
public:

    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        IC(nums);

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int tmp = nums[i] + nums[l] + nums[r];
                if (tmp < 0) l++;
                else if (tmp > 0) r--;
                else {
                    result.push_back({nums[i], nums[l], nums[r]});

                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                }
            }
        }

        return result;
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> rel = {{-1, -1, 2},
                               {-1, 0,  1}};
//    IC(nums, rel);
//    IC(solution->threeSum(nums));
//
//    vector<int> nums_2 = {0, 0, 0};
//    IC();
//    IC(nums_2);
//    IC(solution->threeSum(nums_2));


    vector<int> nums_3 = {-2, 1, 1, 1};
    vector<int> rel_3 = {{-2, 1, 1}};
    IC();
    IC(nums_3, rel_3);
    IC(solution->threeSum(nums_3));

    // code end

    delete solution;
    return 0;
}


