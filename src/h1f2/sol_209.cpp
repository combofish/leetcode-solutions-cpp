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
        vector<int> dp(n+1, 0);
        for(int i = 0; i<n; ++i){
            dp[i+1] += dp[i] + nums[i];
        }

        IC(dp);
        int ans = n+1;

        int lk = 0, rk = 0;

        while(rk <= n){
            while(dp[rk] - dp[lk] < target && rk < n){
                ++rk;
            }

            while(lk + 1 <= rk && dp[rk] - dp[lk + 1] >= target){
                ++lk;
            }

            if(dp[rk] - dp[lk] >= target) ans = std::min(ans, rk - lk);

            IC(lk, rk);
            ++rk;
        }


        return ans == n+1 ? 0: ans;

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