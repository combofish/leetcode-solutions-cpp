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
    int minCostClimbingStairs(vector<int> &cost) {
        std::pair<int,int> dp{0,0};
        for(int i = 2; i<= cost.size(); i++){
            int tmp = std::min(dp.second + cost[i-1], dp.first + cost[i-2]);
            dp.first = dp.second;
            dp.second = tmp;
        }

        return dp.second;

    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int rel = 6;
    IC(cost, rel);
    IC(solution->minCostClimbingStairs(cost));

    // code end

    delete solution;
    return 0;
}


