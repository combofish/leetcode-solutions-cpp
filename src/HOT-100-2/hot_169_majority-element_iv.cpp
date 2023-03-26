/**
-- question: 多数元素
-- method:
 - [ ] 哈希表
 - [ ] 排序
 - [ ] 随机化
 - [-] 分治
 - [*] Boyer-Moore 投票算法

--result:

-- analyse:
Time: O( nlog(n) )
Space: O( log(n) )
 */

#include <random>
#include "../combofish_utils.hpp"
#include <algorithm>


class Solution {

    // function start.
public:
    int majorityElement(vector<int> &nums) {
        return majority_element_select(nums, 0, nums.size() - 1);
    }

private:
    int count_in_range(const vector<int> &nums, int target, int lk, int rk) {
        int cnt = 0;
        for (int i = lk; i <= rk; i++)
            if (nums[i] == target)
                cnt++;

        return cnt;
    }

    int majority_element_select(const vector<int> &nums, int lk, int rk) {
        if (lk == rk) return nums[lk];
        auto mid = (lk + rk) >> 1;

        auto left_majority = majority_element_select(nums, lk, mid);
        auto right_majority = majority_element_select(nums, mid + 1, rk);

        if (count_in_range(nums, left_majority, lk, rk) > (rk - lk + 1) / 2) return left_majority;
        if (count_in_range(nums, right_majority, lk, rk) > (rk - lk + 1) / 2) return right_majority;
        return -1;
    }


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


