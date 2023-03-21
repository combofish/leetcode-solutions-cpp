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

    // function start.
private:


public:
    /**
     * greedy
     * @param prices
     * @return
     */
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 1) return 0;

        std::pair<int, int> dp;
        dp.first = prices[0];
        dp.second = 0;

        for (int i = 1; i < prices.size(); i++) {
            dp.first = std::min(dp.first, prices[i]);
            dp.second = std::max(dp.second, prices[i] - dp.first);
        }

        return dp.second;
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int rel = 5;
    IC(prices, rel);
    IC(solution->maxProfit(prices) == rel);

    // code end

    delete solution;
    return 0;
}


