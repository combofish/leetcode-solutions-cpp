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

class Solution {

    // function start.
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;

        int ans = INT_MAX;

        int lk = 0, rk = 0;

        int cur_sum = 0;
        while(rk < n){
            cur_sum += nums[rk];
            while(cur_sum >= target){
                ans = std::min(ans, rk - lk + 1);
                cur_sum -= nums[lk];
                ++lk;
            }
            ++rk;
        }

        return ans == INT_MAX? 0 : ans;

    }


private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};

    IC(target, nums);

    IC(solution->minSubArrayLen(target, nums));

    // code end

    return 0;
}