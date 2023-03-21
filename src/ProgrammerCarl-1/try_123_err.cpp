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
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 1) return 0;

        vector<int> maxNums;

        int tmpMax = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] >= prices[i - 1]) {
                tmpMax += prices[i] - prices[i - 1];
            } else {
                maxNums.push_back(tmpMax);
                tmpMax = 0;
            }
        }

        if (tmpMax) maxNums.push_back(tmpMax);
        IC(maxNums);

        if (maxNums.size() == 1) return maxNums.front();

        std::sort(maxNums.begin(), maxNums.end(), std::greater<>());
        IC(maxNums);
        return maxNums[0] + maxNums[1];

    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int rel = 6;
    IC(prices, rel);
    IC(solution->maxProfit(prices));

    // code end

    delete solution;
    return 0;
}


