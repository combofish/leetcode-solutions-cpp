/**
-- question: 最短无序连续子数组
-- method:
 - [ ] 排序
 - [*] 一次遍历

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <climits>
#include <cstdint>

class Solution {

    // function start.
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int n = nums.size();
        int maxN = INT_MIN, right = -1;
        int minN = INT_MAX, left = -1;
        for (int i = 0; i < n; i++) {
            if (maxN > nums[i]) right = i;
            else
                maxN = nums[i];

            if (minN < nums[n - i - 1]) left = n - i - 1;
            else
                minN = nums[n - i - 1];

            IC(left, right, minN, maxN);
        }


        return right == -1 ? 0 : right - left + 1;
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
