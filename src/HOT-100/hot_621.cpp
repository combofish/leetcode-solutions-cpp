/**
-- question:
-- method:
 - [*] 模拟
 - [ ] 构造

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

    int leastInterval(vector<char> &tasks, int n) {
        unordered_map<char, int> cache;
        for (const auto &item: tasks)
            cache[item]++;

        int nKinds = cache.size();


        IC(cache, nKinds);
        IC(tasks);

        vector<int> nextValid, rest;
        for (const auto &item: cache) {
            nextValid.emplace_back(1);
            rest.emplace_back(item.second);
        }
        IC(nextValid, rest);


        int time = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            ++time;
            int minNextValid = INT_MAX;
            for (int j = 0; j < nKinds; j++) {
                if (rest[j])
                    if (nextValid[j] < minNextValid) minNextValid = nextValid[j];
            }

            IC(time, minNextValid);

            time = max(time, minNextValid);
            int best = -1;
            for (int j = 0; j < nKinds; j++) {
                if (rest[j] && nextValid[j] <= time) {
                    if (best == -1 || rest[j] > rest[best]) best = j;
                }
            }

            nextValid[best] = time + n + 1;
            --rest[best];


            IC(nextValid, rest, best, time);
            IC('-');
        }


        return time;


    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    int rel = 8;

    IC(tasks, n, rel);

    IC(solution->leastInterval(tasks, n) == rel);
    // code end

    return 0;
}


