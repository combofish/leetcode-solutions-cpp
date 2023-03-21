/**
-- method: 计算分布函数

--result:
执行用时：80 ms, 在所有 C++ 提交中击败了40.00%的用户
内存消耗：26.8 MB, 在所有 C++ 提交中击败了8.15%的用户
通过测试用例：8 / 8

-- analyse:
Time: O(1)
Space: O(1)

 */

#include "combofish_utils.hpp"
#include <cmath>
#include <random>

class Solution {
  std::mt19937 gen{std::random_device{}()};
  std::uniform_real_distribution<double> dis;
  double xc, yc, r;

public:
  // function start.
  Solution(double radius, double x_center, double y_center)
      : dis(0, 1), xc(x_center), yc(y_center), r(radius){};

  vector<double> randPoint() {
    double u = dis(gen), theta = dis(gen) * 2 * std::acos(-1.0);
    double r = std::sqrt(u);
    return {xc + r * std::cos(theta) * this->r, yc + r * sin(theta) * this->r};
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
