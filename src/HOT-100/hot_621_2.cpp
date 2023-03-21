/**
-- question:
-- method:
 - [ ] 模拟
 - [*] 构造

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
        unordered_map<int, int> cache;
        for (const auto &item: tasks) {
            ++cache[item];
        }

        int maxExec = std::max_element(cache.begin(), cache.end(), [](const auto &a, const auto &b) {
            return a.second < b.second;
        })->second;
        int maxCount = std::accumulate(cache.begin(), cache.end(), 0, [=](int acc, const auto &a) {
            return acc + (a.second == maxExec);
        });

        IC(maxExec, maxCount, tasks.size());

        return std::max((maxExec - 1) * (n + 1) + maxCount, static_cast<int>(tasks.size()));
        //return std::max((maxExec - 1) * (n + 1) + maxCount,tasks.size());


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


