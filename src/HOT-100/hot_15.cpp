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

            unordered_set<int> uset;
            for (int j = i + 1; j < nums.size(); j++) {
                IC(i, j, uset);

                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) continue;
                int c = 0 - nums[i] - nums[j];

                if (uset.find(c) != uset.end()) {
                    IC();
                    result.push_back({c, nums[i], nums[j]});
                    uset.erase(c);
                } else {
                    uset.insert(nums[j]);
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


