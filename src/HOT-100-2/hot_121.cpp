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
        int lower = prices.front();
        int ans = 0;
        for(auto &n: prices){
            if(n < lower){
                lower = n;
            }else{
                ans = std::max(ans, n - lower);
            }
        }

        return ans;
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


