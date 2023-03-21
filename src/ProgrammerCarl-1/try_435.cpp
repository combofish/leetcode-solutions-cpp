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
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end(),[](const vector<int> &a, const vector<int> &b){
           return a.back() < b.back();
        });

        int ans = 1;
        int end = intervals.front().back();
        for(int i = 1;i < intervals.size(); i++){
            if(end <= intervals[i].front()){
                ans++;
                end = intervals[i].back();
            }
        }

        return intervals.size() - ans;

    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<vector<int>> intervals = {{1, 2},
                                     {2, 3},
                                     {3, 4},
                                     {1, 3}};
    int rel = 1;

    IC(intervals, rel);
    IC(solution->eraseOverlapIntervals(intervals));
    // code end

    delete solution;
    return 0;
}


