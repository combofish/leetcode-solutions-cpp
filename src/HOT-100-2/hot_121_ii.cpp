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
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,0));

        dp.front().front() = -prices.front();
        for(int i = 1;i< n; i++){
            dp[i].front() = std::max(dp[i-1].front(), -prices[i]);
            dp[i].back() = std::max(dp[i-1].back(), dp[i-1].front() + prices[i]);
        }

        return dp.back().back();

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> res = {7,1,5,3,6,4};
    int ans = 5;
    IC(res, ans);

    IC(solution->maxProfit(res));

    // code end

    return 0;
}


