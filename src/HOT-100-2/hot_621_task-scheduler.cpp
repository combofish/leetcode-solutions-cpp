/**
-- question: 任务调度器
-- method:
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
        unordered_map<char, int> ump;
        for (const auto &c: tasks) ump[c]++;

        IC(ump);

        auto maxExec = std::max_element(ump.cbegin(), ump.cend(),
                                        [](const auto &a, const auto &b) {
                                            return a.second < b.second;
                                        })->second;
        auto maxCount = std::accumulate(ump.cbegin(), ump.cend(), 0,
                                        [=](int acc, const auto &ele) {
                                            return acc + (ele.second == maxExec);
                                        });

        return std::max(
                (maxExec - 1) * (n + 1) + maxCount,
                static_cast<int>(tasks.size())
        );


    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

//    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
//    int n = 2, ans = 8;


    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 0;
    int ans = 6;

    IC(tasks,n, ans);
    IC(solution->leastInterval(tasks,n));
    // code end

    return 0;
}


