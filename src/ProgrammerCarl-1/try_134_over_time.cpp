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
        for (int i = 0; i < cost.size(); i++) {
            int rest = gas[i] - cost[i];
            int index = (i + 1) % gas.size();

            while (rest > 0 && index != i) {
                rest += gas[index] - cost[index];
                index = (index + 1) % cost.size();
            }

            if (rest >= 0 && index == i) return i;

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


