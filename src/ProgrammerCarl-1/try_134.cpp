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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int curSum = 0;
        int min = INT_MAX;

        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            if (curSum < min)
                min = curSum;
        }

        // case 1
        if (curSum < 0) return -1;

        // case 2
        if (min >= 0) return 0;

        // case 3
        for (int i = gas.size() - 1; i >= 0; i--) {
            min += gas[i] - cost[i];
            if (min >= 0) return i;
        }

        return -1;

    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    int rel = 3;


    IC(gas, cost, rel);
    IC(solution->canCompleteCircuit(gas, cost));
    // code end

    delete solution;
    return 0;
}


