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

    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a.front() < b.front();
        });

        vector<vector<int>> result;
        int left = intervals.front().front();
        int right = intervals.front().back();


        for (int i = 1; i < intervals.size(); ++i) {
            if (right < intervals[i].front()) {
                result.push_back({left, right});
                left = intervals[i].front();
                right = intervals[i].back();

            } else {
                right = std::max(right, intervals[i].back());
            }
        }


        result.push_back({left, right});

        return result;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<vector<int>> intervals = {{1,  3},
                                     {2,  6},
                                     {8,  10},
                                     {15, 18}};
    vector<vector<int>> rel = {{1,  6},
                               {8,  10},
                               {15, 18}};

    IC(intervals, rel);
    IC(solution->merge(intervals));
    // code end

    delete solution;
    return 0;
}


