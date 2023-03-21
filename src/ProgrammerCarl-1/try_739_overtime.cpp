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
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> record(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            int j = i + 1;
            while (j < temperatures.size()) {
                if (temperatures[j] > temperatures[i]) {
                    record[i] = j - i;
                    break;
                }
                j++;
            }
        }

        return record;
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> rel = {1, 1, 4, 2, 1, 1, 0, 0};

    IC(temperatures, rel);
    IC(solution->dailyTemperatures(temperatures));
    // code end

    delete solution;
    return 0;
}


