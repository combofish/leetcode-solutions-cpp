/**
-- question: 除自身以外数组的乘积
-- method:
 - [ ] count zero
 - [-] 左右乘积列表
 - [ ] 空间复杂度 O(1) 的方法

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
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();

        vector<int> l(n, 1), r(n, 1);
        for (int i = 1; i < n; i++) {
            l[i] = l[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            r[i] = r[i + 1] * nums[i + 1];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = l[i] * r[i];

        return ans;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> nums = {-1, 1, 0, -3, 3},
            ans = {0, 0, 9, 0, 0};

    IC(nums, ans);
    IC(solution->productExceptSelf(nums));

    // code end

    return 0;
}


