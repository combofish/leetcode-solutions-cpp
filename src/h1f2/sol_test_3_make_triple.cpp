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
    int getSquareN(int n) {

        vector<int> dp(n + 1, 0);
        dp[1] = 0;
        dp[2] = 0;
        dp[3] = 1;

        for (int i = 4; i <= n; ++i) {

            auto tmp = dp[i - 1] + dp[i - 2];

            dp[i] = tmp + 1;
        }
        return dp.back();
    }

private:
    
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start


    int n = 40;
    IC(n);

    IC(solution->getSquareN(n));
    // code end

    return 0;
}