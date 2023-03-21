/**
-- method: 向量叉乘

--result:
执行用时：4 ms, 在所有 C++ 提交中击败了42.64%的用户
内存消耗：9.9 MB, 在所有 C++ 提交中击败了93.87%的用户
通过测试用例：206 / 206

-- analyse:
Time: O(1)
Space: O(1)

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
  // function start.
  bool isBoomerang(vector<vector<int>> &points) {
    vector<int> v1 = {points[1][0] - points[0][0], points[1][1] - points[0][1]};
    vector<int> v2 = {points[2][0] - points[0][0], points[2][1] - points[0][1]};

    return 0 != v1[0] * v2[1] - v1[1] * v2[0];
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
