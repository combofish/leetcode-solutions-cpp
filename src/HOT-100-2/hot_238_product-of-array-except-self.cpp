/**
-- question: 除自身以外数组的乘积
-- method:
 - [-] count zero
 - [ ] 左右乘积列表
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
        int has_zero = 0;
        int product = std::accumulate(nums.cbegin(), nums.cend(), 1, [&](int acc, const int num) {
            if (num == 0) {
                ++has_zero;
                return acc;
            } else {
                acc *= num;
                return acc;
            }
        });

        IC(has_zero, product);

        int n = nums.size();
        vector<int> ans(n, 0);
        if (has_zero > 1) {
            return ans;
        } else if (has_zero == 1) {
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0)
                    ans[i] = product;
            }
        } else {
            for (int i = 0; i < n; i++) {
                ans[i] = product / nums[i];
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

    vector<int> nums = {-1, 1, 0, -3, 3},
            ans = {0, 0, 9, 0, 0};

    IC(nums, ans);
    IC(solution->productExceptSelf(nums));

    // code end

    return 0;
}


