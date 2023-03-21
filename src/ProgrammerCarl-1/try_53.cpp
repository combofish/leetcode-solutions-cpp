/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
private:

    // function start.
public:
    int maxSubArray(vector<int> &nums) {
        int result = INT_MIN;
        int count = 0;

        for (auto n: nums) {
            count += n;
            result = std::max(count, result);
            if (count < 0) count = 0;
        }
        return result;
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int rel = 6;
    IC(nums, rel);
    IC(solution->maxSubArray(nums));

    // code end

    delete solution;
    return 0;
}


