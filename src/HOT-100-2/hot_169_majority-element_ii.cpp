/**
-- question: 多数元素
-- method:
 - [ ] 哈希表
 - [-] 排序
 - [ ] 随机化
 - [ ] 分治
 - [*] Boyer-Moore 投票算法

--result:

-- analyse:
Time: O( nlog(n) )
Space: O( log(n) )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int majorityElement(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int ans = 2;
    IC(nums, ans);

    IC(solution->majorityElement(nums));


    // code end

    return 0;
}


