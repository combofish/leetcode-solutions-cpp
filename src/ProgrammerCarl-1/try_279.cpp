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
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp.front() = 0;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j * j <= i; j++)
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);

        return dp.back();
    }

    int numSquares_2(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp.front() = 0;
        for (int j = 1; j * j < n; j++)
            for (int i = 0; i <= n; i++)
                if (j * j <= i) dp[i] = std::min(dp[i], dp[i - j * j] + 1);


        return dp.back();
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    int n = 12;
    int rel = 3;
    vector<int> nums = {4, 4, 4};
    IC(n, rel, nums);

    IC(solution->numSquares(n) == rel);
    IC(solution->numSquares_2(n) == rel);

    // code end

    delete solution;
    return 0;
}


