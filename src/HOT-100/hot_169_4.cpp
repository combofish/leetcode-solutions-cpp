/**
-- question: 多数元素
-- method:
 - [] 哈希表
 - [] 排序
 - [] 随机化
 - [*] 分治
 - [] Boyer-Moore 投票算法

--result:

-- analyse:
Time: O( nlog(n) )
Space: O( log(n) )
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int majorityElement(vector<int> &nums) {
        return majorityElementRecord(nums, 0, nums.size() - 1);
    }

private:
    int countInRange(const vector<int> &nums, int target, int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++)
            if (nums[i] == target) ++count;

        return count;
    }

    int majorityElementRecord(const vector<int> &nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = (left + right) >> 1;
        int left_majority = majorityElementRecord(nums, left, mid);
        int right_majority = majorityElementRecord(nums, mid + 1, right);

        if (countInRange(nums, left_majority, left, right) > (right - left + 1) >> 1) return left_majority;
        if (countInRange(nums, right_majority, left, right) > (right - left + 1) >> 1) return right_majority;

        return -1;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int rel = 2;

    IC(nums, rel);
    IC(solution->majorityElement(nums) == rel);

    // code end

    return 0;
}


