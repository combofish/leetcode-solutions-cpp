/**
-- question: 最短无序连续子数组
-- method:
 - [*] 排序
 - [ ] 一次遍历

--result:

-- analyse:
Time: O( nlog(n) )
Space: O( n )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int findUnsortedSubarray(vector<int> &nums) {
        if (std::is_sorted(nums.begin(), nums.end())) return 0;

        vector<int> numsSorted(nums);
        sort(numsSorted.begin(), numsSorted.end());

        int left = 0;
        while (nums[left] == numsSorted[left]) ++left;
        int right = nums.size() - 1;
        while (nums[right] == numsSorted[right]) --right;
        return right - left + 1;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    int rel = 5;

    IC(nums, rel);
    IC(solution->findUnsortedSubarray(nums) == rel);

    // code end

    return 0;
}
