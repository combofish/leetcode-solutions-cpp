/**
-- method: add_idx, sort, for,

--result:
执行用时： 344 ms , 在所有 C++ 提交中击败了 11.82% 的用户
内存消耗： 25.2 MB , 在所有 C++ 提交中击败了 71.68% 的用户
通过测试用例： 19 / 19

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
    for (int i = 0; i < n; ++i)
      intervals[i].emplace_back(i);

    std::sort(intervals.begin(), intervals.end(),
              [](auto &v1, auto &v2) { return v1[0] < v2[0]; });

    IC(intervals);

    for (int i = 0; i < n; ++i) {
      int curr_end = intervals[i][1];

      for (int j = i; j < n; j++) {
        if (intervals[j][0] >= curr_end) {
          IC(intervals[j], curr_end, intervals[j][2]);
          res[intervals[i][2]] = intervals[j][2];
          break;
        }
      }

      //      res[i] = min_idx;
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
