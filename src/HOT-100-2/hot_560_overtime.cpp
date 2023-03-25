/**
-- question: 和为K的子数组
-- method:
 - [ ] 枚举
 - [ ] 前缀和 + 哈希表优化

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

    int subarraySum(vector<int>& nums, int k) {
        auto n = nums.size();
        int res = 0;

        for(int i = 0; i< n; i++){
            int sum = 0;
            for(int j = i; j< n;j++){
                sum += nums[j];
                if(sum == k) ++res;
            }
        }

        return res;

    }
private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1,2,3};
    int k = 3;
    int ans = 2;
    IC(nums, k, ans);

    IC(solution->subarraySum(nums, k));

    // code end

    return 0;
}


