/**
-- question: 颜色分类
-- method:
 - []

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
    void sortColors(vector<int> &nums) {
        int rec[3] = {0};
        for (auto &n: nums)
            rec[n]++;

        while (rec[2]--)
            nums[rec[0] + rec[1] + rec[2]] = 2;

        while (rec[1]--)
            nums[rec[0] + rec[1]] = 1;

        while (rec[0]--)
            nums[rec[0]] = 0;
        // for (int i = 0; i < rec[0]; i++) nums[i] = 0;
        // for (int j = rec[0]; j < rec[0] + rec[1]; j++) nums[j] = 1;
        // for (int k = rec[0] + rec[1]; k < nums.size(); k++) nums[k] = 2;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    vector<int> ans = {0, 0, 1, 1, 2, 2};

    IC(nums, ans);
    solution->sortColors(nums);
    IC(nums);
    // code end

    return 0;
}
