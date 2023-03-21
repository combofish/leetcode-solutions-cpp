/**
-- method: 拒绝采样

--result:
执行用时：96 ms, 在所有 C++ 提交中击败了16.05%的用户
内存消耗：26.4 MB, 在所有 C++ 提交中击败了55.56%的用户
通过测试用例：8 / 8

-- analyse:
Time: O(1)
Space: O(1)

 */

#include "combofish_utils.hpp"
#include <random>

class Solution {
  std::mt19937 gen{std::random_device{}()};
  std::uniform_real_distribution<double> dis;
  double xc, yc, r;

public:
  // function start.
  Solution(double radius, double x_center, double y_center)
      : dis(-radius, radius), xc(x_center), yc(y_center), r(radius){};

  vector<double> randPoint() {
    while (true) {
      double x = dis(gen), y = dis(gen);
      if (x * x + y * y <= r * r) {
        return {xc + x, yc + y};
      }
    }
  }
  // function end.
};

int main() {

  Solution *solution = new Solution(1.0, 0.0, 0.0);

  // code start
  for (int i = 0; i < 20; i++)
    IC(solution->randPoint());
  return 0;
}
