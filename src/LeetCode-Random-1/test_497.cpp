/**
-- method: 前缀和 + 二分查找

--result:
执行用时：80 ms, 在所有 C++ 提交中击败了52.35%的用户
内存消耗：65.7 MB, 在所有 C++ 提交中击败了64.62%的用户
通过测试用例：35 / 35

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <random>

class Solution {
private:
  vec_t arr;
  vector<vector<int>> &rects;
  std::mt19937 gen{std::random_device{}()};

public:
  // function start.
  Solution(vector<vector<int>> &rects) : rects{rects} {
    this->arr.emplace_back(0);
    for (auto &rect : rects)
      this->arr.emplace_back(arr.back() +
                             (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
  }

  vector<int> pick() {
    IC(this->arr);

    std::uniform_int_distribution<int> dis(0, arr.back() - 1);
    int k = dis(gen) % arr.back();
    int rectIndex =
        std::upper_bound(arr.begin(), arr.end(), k) - arr.begin() - 1;
    k = k - arr[rectIndex];
    int a = rects[rectIndex][0], b = rects[rectIndex][1];
    int y = rects[rectIndex][3];
    int col = y - b + 1;
    int da = k / col;
    int db = k - col * da;
    return {a + da, b + db};
  }
  // function end.
};

int main() {

  vector<vector<int>> res = {{-2, -2, 1, 1}, {2, 2, 4, 6}};
  Solution *solution = new Solution(res);

  IC(res);
  IC(solution->pick());
  IC(solution->pick());
  IC(solution->pick());
  IC(solution->pick());
  // code start
  return 0;
}
