/**
-- question: 除自身以外数组的乘积
-- method:
 - [ ] 左右乘积列表
 - [ ] 左右乘积列表

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
        vector<int> result(n), left(n), right(n);
        left.front() = 1;
        right.back() = 1;
        for(int i = 1; i<n; i++)
            left[i] = left[i-1] * nums[i-1];

        for(int i = n-2; i>=0; i--)
            right[i] = nums[i+1] * right[i+1];

        for(int i = 0; i< n;i++)
            result[i] = left[i] * right[i];


        IC(left, right, result);
        return result;

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 2, 3, 4};
    vector<int> rel = {24, 12, 8, 6};

    IC(nums, rel);
    IC(solution->productExceptSelf(nums));

    // code end

    return 0;
}


