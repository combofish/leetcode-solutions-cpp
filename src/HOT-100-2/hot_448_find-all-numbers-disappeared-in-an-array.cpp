/**
-- question: 找到所有数组中消失的数字
-- method:
 - [ ] unordered_set
 - [*] 原地修改

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {

        int n = nums.size();
        for (auto &num: nums) {
            auto x = (num - 1) % n;
            nums[x] += n;
        }

        IC(n, nums);

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                ans.emplace_back(i + 1);
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
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = {5, 6};

    IC(nums, ans);
    IC(solution->findDisappearedNumbers(nums));

    // code end

    return 0;
}
