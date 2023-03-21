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
#include <algorithm>

class Solution {

    // function start.
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {

        std::sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a.front() < b.front();
        });

        IC(intervals);
        vector<vector<int>> ans;

        int start = intervals.front().front();
        int end = intervals.front().back();

        for (auto &item: intervals) {
            if (end < item.front()) {
                ans.push_back({start, end});
                start = item.front();
                end = item.back();
            } else {
                // end = item.back();

                end = std::max(item.back(), end);
            }
        }

        // if(ans.back().front() != start || ans.back().back() != end){
        //   ans.push_back({start, end});
        // }

        ans.push_back({start, end});


        return ans;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = {{1, 6}, {8, 10}, {15, 18}};

    IC(intervals, result);

    IC(solution->merge(intervals));
    // code end

    return 0;
}
