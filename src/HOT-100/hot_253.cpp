/**
-- question: 会议室 II
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <functional>
#include <queue>

class Solution {

    // function start.
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a.front() < b.front();
        });

        IC(intervals);

        std::priority_queue<int, vector<int>, std::greater<int>> heap;
        for (const auto &item: intervals) {
            if (!heap.empty() && heap.top() <= item.front()) heap.pop();

            heap.push(item.back());
            //            IC(heap);
            outP(heap);
        }


        return heap.size();
    }


private:
    void outP(std::priority_queue<int, vector<int>, std::greater<int>> heap) {
        vector<int> res;
        while (!heap.empty()) {
            res.emplace_back(heap.top());
            heap.pop();
        }

        IC(res);
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    int rel = 2;
    IC(intervals, rel);

    IC(solution->minMeetingRooms(intervals));

    // code end

    return 0;
}
