/**
-- question: 除自身以外数组的乘积
-- method:
 - [ ] 左右乘积列表
 - [*] 左右乘积列表, 优化空间

--result:

-- analyse:
Time: O(N)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> result(n,1);
        for(int i = 1; i< n; i++){
            result[i] = result[i-1] * nums[i-1];
        }

        IC(result);
        int tmp =1;
        for(int i = n-1; i>=0; i--){
            result[i] = result[i] * tmp;
            tmp *= nums[i];
        }
        IC(result);


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


