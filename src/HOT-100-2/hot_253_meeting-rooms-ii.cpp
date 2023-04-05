/**
-- question: 会议室 II
-- method:
 - [-] 优先队列

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"

class Solution {

    // function start.
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {

        std::sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a.front() < b.front();
        });

        IC(intervals);

        std::priority_queue<int, vector<int>, std::greater<int>> heap; // 小顶堆
        for (const auto &item: intervals) {
            if (!heap.empty() && heap.top() <= item.front()) {
                heap.pop();
            }
            heap.push(item.back());

            IC(heap);
        }

        heap.push(3);
        heap.push(4);
        IC(heap.top());


        return heap.size();
    }


private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<int>> inputs = {{0,  30},
                                  {5,  10},
                                  {15, 20}};
    int ans = 2;

    IC(inputs, ans);
    IC(solution->minMeetingRooms(inputs));

    // code end

    return 0;
}
