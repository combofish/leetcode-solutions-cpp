/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <climits>

class Solution {
public:
    // function start.

    int minSubArrayLen(int target, vector<int> &nums) {
        int i = 0;
        int res = INT_MAX;
        int sum = 0;
        int sub_length = 0;
        for (int j = 0; j < nums.size(); ++j) {
            sum += nums[j];
            while (sum >= target) {
                sub_length = j - i + 1;
                res = sub_length < res ? sub_length : res;

                sum -= nums[i++];
            }
        }

        return res == INT_MAX ? 0 : sub_length;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    int target = 7;
    vec_t nums = {2, 3, 1, 2, 4, 3};
    IC(target, nums);

    IC(solution->minSubArrayLen(target, nums));
    // code end

    delete solution;
    return 0;
}
