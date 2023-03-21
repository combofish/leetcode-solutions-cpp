/**
-- question: 数组中出现次数超过一半的数字
-- method:
 - [ ] 哈希表
 - [ ] 排序
 - [ ] 随机化 -- * --
 - [*] 分治
 - [ ] Boyer-Moore 投票算法 -- * --

--result:

-- analyse:
Time: O(nlogn)
Space: O(logn)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int majorityElement(vector<int> &nums) {
        return majority_element_record(nums, 0, nums.size() - 1);
    }

private:
    int count_in_range(const vector<int> &nums, int target, int left, int right) {
        int cnt = 0;
        for (int i = left; i <= right; i++)
            if (nums[i] == target) ++cnt;
        return cnt;
    }

    int majority_element_record(const vector<int> &nums, int left, int right) {
        if (left == right) return nums[left];

        int mid = (left + right) >> 1;
        auto left_majority = majority_element_record(nums, left, mid);
        auto right_majority = majority_element_record(nums, mid + 1, right);

        if (count_in_range(nums, left_majority, left, right) > (right - left + 1) / 2) return left_majority;
        if (count_in_range(nums, right_majority, left, right) > (right - left + 1) / 2) return right_majority;
        return -1;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> result = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int rel = 2;
    IC(result, rel);
    IC(solution->majorityElement(result));
    // code end

    return 0;
}
