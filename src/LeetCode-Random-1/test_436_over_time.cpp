/**
-- method: for, for,

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <valarray>

class Solution {
public:
  // function start.
  vector<int> findRightInterval(vector<vector<int>> &intervals) {
    int n = intervals.size();
    vec_t res(n, -1);

    if (n == 1)
      return res;

    for (int i = 0; i < n; ++i) {
      int curr_end = intervals[i][1];
      int min_idx = -1;
      for (int j = 0; j < n; ++j) {
        // if (i == j)
        //   continue;

        if (intervals[j][0] >= curr_end) {
          if (min_idx == -1) {
            min_idx = j;
          } else {
            if (intervals[j][0] - curr_end <=
                intervals[min_idx][0] - curr_end) {
              min_idx = j;
            }
          }
        }
      }

      res[i] = min_idx;
    }

    return res;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  vector<vector<int>> intervals = {{3, 4}, {2, 3}, {1, 2}};
  IC(intervals);

  IC(solution->findRightInterval(intervals));
  vec_t res = {-1, 0, 1};
  IC(res);

  IC();
  mat_t intervals2 = {{1, 2}, {2, 3}, {0, 1}, {3, 4}};
  vec_t res2 = {1, 3, 0, -1};
  IC(intervals2, res2);
  IC(solution->findRightInterval(intervals2));
  return 0;
}
