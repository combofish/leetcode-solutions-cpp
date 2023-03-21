/**
-- method:

--result:

-- analyse:
Time: O(n)
Space: O(1)

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
private:

    // function start.
public:

    int maxProfit(vector<int> &prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            result += std::max(0, prices[i] - prices[i - 1]);
        }

        return result;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int rel = 7;
    IC(prices, rel);

    IC(solution->maxProfit(prices));
    // code end

    delete solution;
    return 0;
}


