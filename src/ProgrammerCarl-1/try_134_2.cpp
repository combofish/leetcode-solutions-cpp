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
        int totalSum = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++) {
            int tmp = gas[i] - cost[i];
            curSum += tmp;
            totalSum += tmp;

            if (curSum < 0) {
                start = i + 1;
                curSum = 0;
            }
        }

        if (totalSum < 0) return -1;
        return start;
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


