/**
-- question: 最短无序连续子数组
-- method:
 - [ ] 排序
 - [*] 一次遍历

--result:

-- analyse:
Time: O( n )
Space: O( 1 )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int n = nums.size();

        int maxN = INT_MIN, rk = -1;
        int minN = INT_MAX, lk = -1;

        for (int i = 0; i < n; i++) {
            if (maxN > nums[i]) rk = i;
            else maxN = nums[i];


            if (minN < nums[n - i - 1]) lk = n - i - 1;
            else minN = nums[n - i - 1];
        }

        return rk == -1 ? 0 : rk - lk + 1;
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


