/**
-- question:
-- method:
 - []

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
        std::sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
           return a.front() == b.front() ? a.back() < b.back() : a.front() < b.front();
        });
        IC(intervals);

        std::priority_queue<int, vector<int>, std::greater<int>> q;
        for(auto &item: intervals){
            if(!q.empty() && q.top() < item.front()){
                q.pop();
                q.push(item.back());
            }else{
                q.push(item.back());
            }
        }
        IC(q);
        return q.size();
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<vector<int>> intervals = {{0, 30}, {5, 10}, { 15, 20 }};
    int ans = 2;

    IC(intervals, ans);
    IC(solution->minMeetingRooms(intervals));


    // code end

    return 0;
    }