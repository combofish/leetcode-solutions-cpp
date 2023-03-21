/**
-- question:
-- method:

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int maxSubArray(vector<int> &nums) {
        int result = INT_MIN;
        int count = 0;
        for(auto n: nums){
            count+=n;

            if(count > result) result = count;
            if(count < 0) count = 0;
        }

        return result;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int rel = 6;
    IC(nums, rel);
    IC(solution->maxSubArray(nums) == rel);

    // code end

    return 0;
}


