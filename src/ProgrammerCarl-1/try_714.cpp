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
    int maxProfit(vector<int> &prices, int fee) {

        int minPrice = prices[0];
        int result = 0;

        for (auto price: prices) {
            if (price < minPrice) minPrice = price;

//            IC(price, result, minPrice);
            if (price >= minPrice && price <= minPrice + fee)
                continue;

            if (price > minPrice + fee) {
                result += price - minPrice - fee;
                minPrice = price - fee;
            }

            IC(price, result, minPrice);
        }
        return result;
    }


    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    int rel = 8;
    IC(prices, fee, rel);

    IC(solution->maxProfit(prices, fee));

    out_line();
    IC();
    vector<int> prices_2 = {1, 3, 7, 5, 10, 3};
    int fee_2 = 3;
    int rel_2 = 6;

    IC(prices_2, fee_2, rel_2);
    IC(solution->maxProfit(prices_2,fee_2));
    // code end

    delete solution;
    return 0;
}


