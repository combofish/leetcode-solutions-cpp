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

        stack<int> sta;
        sta.push(0);
        for (int i = 1; i < temperatures.size(); i++) {
            if (temperatures[sta.top()] > temperatures[i]) {
                sta.push(i);
            } else if (temperatures[sta.top()] == temperatures[i]) {
                sta.push(i);
            } else {
                while (!sta.empty() && temperatures[i] > temperatures[sta.top()]) {
                    record[sta.top()] = i - sta.top();
                    sta.pop();
                }

                sta.push(i);
            }
        }

        return record;
    }


    vector<int> dailyTemperatures_2(vector<int> &temperatures) {
        vector<int> record(temperatures.size(), 0);
        stack<int> sta;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!sta.empty() && temperatures[i] > temperatures[sta.top()]) {
                record[sta.top()] = i - sta.top();
                sta.pop();
            }

            sta.push(i);
            out_sta(sta);

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
    IC(solution->dailyTemperatures_2(temperatures));
    // code end

    delete solution;
    return 0;
}


