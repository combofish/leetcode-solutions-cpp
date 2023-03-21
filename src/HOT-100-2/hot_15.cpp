/**
-- question:
-- method:
 - [ ] 排序+双指针 

--result:

-- analyse:
Time: O(N^2)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                auto tmp = nums[i] + nums[l] + nums[r];
                if (tmp > 0) r--;
                else if (tmp < 0)
                    l++;
                else {
                    result.push_back({nums[i], nums[l], nums[r]});

                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }

                    while (l < r && nums[r - 1] == nums[r]) {
                        r--;
                    }

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

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = {{-1, -1, 2}, {-1, 0, 1}};

    IC(nums, res);

    IC(solution->threeSum(nums));
    // code end

    return 0;
}
