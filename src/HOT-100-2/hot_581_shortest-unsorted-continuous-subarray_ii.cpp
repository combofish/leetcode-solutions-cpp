/**
-- question: 最短无序连续子数组
-- method:
 - [-] 排序
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
        if (std::is_sorted(nums.cbegin(), nums.cend())) return 0;

        auto sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        int lk = 0;
        while (nums[lk] == sorted_nums[lk]) ++lk;

        int rk = nums.size() - 1;
        while (nums[rk] == sorted_nums[rk]) --rk;

        return rk - lk + 1;

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    int ans = 5;

//    vector<int> nums = {1, 2, 3, 4};
//    int ans = 0;

    IC(nums, ans);

    IC(solution->findUnsortedSubarray(nums));
    // code end

    return 0;
}


