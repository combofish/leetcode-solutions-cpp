/**
-- question:
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

    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end(),
                  [](const vector<int> &n1, const vector<int> &n2) {
                      return n1.front() < n2.front();
                  });

        IC(intervals);

        vector<vector<int>> result;

        vector<int> tmp;
        tmp = intervals.front();
        for (int i = 1; i < intervals.size(); i++) {
            if (tmp.back() < intervals[i].front()) {
                result.emplace_back(tmp);

                tmp = intervals[i];
            } else {
                // key point
                tmp.back() = std::max(tmp.back(), intervals[i].back());
            }
        }

        // key point
        result.push_back(tmp);

        return result;

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

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

    return 0;
}


