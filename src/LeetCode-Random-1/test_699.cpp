/**
-- method: 维持高度记录，添加一个石头，记录一下最终结果。

--result:
执行用时：116 ms, 在所有 C++ 提交中击败了8.68%的用户
内存消耗：11.3 MB, 在所有 C++ 提交中击败了66.79%的用户
通过测试用例：44 / 44

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"

class Solution {
  int n;
  void cover_high(vector<vector<int>> &high_rec, vector<int> &cur_box) {
    int start = cur_box[0];
    int end = start + cur_box[1];
    IC(start, end, cur_box);

    int high_est = 0;
    for (vector<int> &high : high_rec) {
      int idx = high[0];
      if (start <= idx && idx < end) {
        IC(high);
        high_est = std::max(high_est, high[1]);
      }
    }

    IC(high_est);
    for (vector<int> &high : high_rec) {
      int idx = high[0];
      if (start <= idx && idx < end) {
        high[1] = high_est + cur_box[1];
      }
    }

    IC(high_rec);
    out_line();
  }

public:
  vector<int> fallingSquares(vector<vector<int>> &positions) {
    n = positions.size();
    vector<vector<int>> high_rec(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
      high_rec[i][0] = positions[i][0];
    }

    vector<int> res(n, 0);
    cover_high(high_rec, positions[0]);
    res[0] = high_rec[0][1];

    for (int i = 1; i < n; i++) {
      cover_high(high_rec, positions[i]);

      if (high_rec[i][1] > res[i - 1]) {
        res[i] = high_rec[i][1];
      } else {
        res[i] = res[i - 1];
      }
    }

    return res;
  }
};

int main() {

  Solution *solution = new Solution();

  // code start
  mat_t positions = {{1, 2}, {2, 3}, {6, 1}};
  IC(positions);
  IC(solution->fallingSquares(positions));
  vec_t res = {2, 5, 5};
  IC(res);

  out_line();
  mat_t positions2 = {{1, 2}, {1, 3}};
  IC(positions2);
  IC(solution->fallingSquares(positions2));
  vec_t res2 = {2, 5};
  IC(res2);

  out_line();
  mat_t positions3 = {{2, 1}, {2, 9}, {1, 8}};
  IC(positions3);
  IC(solution->fallingSquares(positions3));
  vec_t res3 = {1, 10, 18};
  IC(res3);
  return 0;
}
