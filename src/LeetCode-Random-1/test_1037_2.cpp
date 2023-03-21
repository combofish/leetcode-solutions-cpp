/**
-- method: 斜率计数，考虑垂直

--result:
执行用时：4 ms, 在所有 C++ 提交中击败了42.64%的用户
内存消耗：10.2 MB, 在所有 C++ 提交中击败了5.22%的用户
通过测试用例：206 / 206

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
  // function start.
  bool isBoomerang(vector<vector<int>> &points) {
    unordered_set<float> uset;
    int inf = 0;

    for (int i = 0; i < 2; i++) {
      for (int j = i + 1; j < 3; j++) {
        if (points[j][0] == points[i][0] && points[j][1] == points[i][1])
          return false;

        if ((points[i][0] - points[j][0]) == 0) {
          inf++;
          continue;
        }
        uset.insert((points[i][1] - points[j][1]) * 1.0 /
                    (points[i][0] - points[j][0]));
      }
    }

    IC(uset, inf);
    if (inf > 1)
      return false;
    if (inf == 1)
      return uset.size() == 2;
    return uset.size() == 3;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();
  mat_t points = {{0, 0}, {0, 2}, {2, 1}};

  IC(points);
  IC(solution->isBoomerang(points));
  IC(1);
  // code start
  return 0;
}
