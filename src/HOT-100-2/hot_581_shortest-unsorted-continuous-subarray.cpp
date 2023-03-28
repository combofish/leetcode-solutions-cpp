/**
-- question:
-- method:
 - []

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
    int findUnsortedSubarray(vector<int> &nums) {
        auto sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end());

        int n = nums.size();

        int lk = -1, rk = n;

        while (lk < rk && lk + 1 < n) {
            if (nums[lk + 1] == sorted_nums[lk + 1]) ++lk;
            else break;
        }

        if (lk + 1 == n) return 0;

        while (rk > lk && rk - 1 >= 0) {
            if (nums[rk - 1] == sorted_nums[rk - 1]) --rk;
            else break;
        }

        IC(lk, rk);

        return rk - lk;


    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
//    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
//    int ans = 5;

    vector<int> nums = {1, 2, 3, 4};
    int ans = 0;

    IC(nums, ans);

    IC(solution->findUnsortedSubarray(nums));
    // code end

    return 0;
}


