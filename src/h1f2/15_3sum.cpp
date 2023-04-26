/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"

class Solution {

    // function start.
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i];
            int lk = i + 1, rk = n - 1;
            while (lk < rk) {
                if (lk > i + 1 && nums[lk] == nums[lk - 1]) {
                    ++lk;
                    continue;

                }
                while (lk < rk && nums[lk] + nums[rk] > target) --rk;

                if (lk == rk) break;
                if (nums[lk] + nums[rk] == target) {
                    // ans.emplace_back(nums[i], nums[lk], nums[rk]);

                    ans.push_back({nums[i], nums[lk], nums[rk]});
                }
                ++lk;
            }
        }

        return ans;

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    string ans = "输出：[[-1,-1,2],[-1,0,1]]";

    IC(nums, ans);
    IC(solution->threeSum(nums));
    // code end

    return 0;
}