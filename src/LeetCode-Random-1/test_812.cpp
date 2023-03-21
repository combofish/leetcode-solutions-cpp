/**
-- method: for, for, for

--result:
执行用时：32 ms, 在所有 C++ 提交中击败了22.60%的用户
内存消耗：7.3 MB, 在所有 C++ 提交中击败了89.55%的用户
通过测试用例：57 / 57

-- analyse:
Time: O(n^3)
Space: O(1)

 */

#include "combofish_utils.hpp"
#include <cmath>

class Solution {
  inline double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    return 0.5 *
           std::abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
  }

public:
  // function start.
  double largestTriangleArea(vector<vector<int>> &points) {
    double area = 0.0;
    int n = points.size();

    for (int i = 0; i < n - 2; i++)
      for (int j = i + 1; j < n - 1; j++)
        for (int k = j + 1; k < n; k++)
          area = std::max(area, triangleArea(points[i][0], points[i][1],
                                             points[j][0], points[j][1],
                                             points[k][0], points[k][1]));

    return area;
  }

  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  mat_t points = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
  IC(points);
  IC(solution->largestTriangleArea(points));

  return 0;
}
