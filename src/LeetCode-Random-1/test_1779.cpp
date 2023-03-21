/**
-- method: for, rec, sort,

--result:
执行用时：240 ms, 在所有 C++ 提交中击败了5.09%的用户
内存消耗：65.8 MB, 在所有 C++ 提交中击败了5.09%的用户
通过测试用例：101 / 101
 */

#include "combofish_utils.hpp"

int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
  vector<pair<int, int>> rec;
  for (int i = 0; i < points.size(); ++i) {
    vector<int> point = points[i];
    if (point[0] == x || point[1] == y) {
      rec.emplace_back(
          std::make_pair(i, std::abs(x - point[0]) + std::abs(y - point[1])));
    }
  }

  if (rec.empty())
    return -1;

  std::sort(rec.begin(), rec.end(),
            [](const pair<int, int> &p1, const pair<int, int> &p2) {
              if (p1.second == p2.second)
                return p1.first < p2.first;
              else
                return p1.second < p2.second;
            });

  IC(rec);
  return rec[0].first;
}

int main() {
  // code start
  int x = 1;
  int y = 1;
  mat_t mat = {{1, 2}, {2, 1}, {1, 2}, {1, 1}, {1, 1}, {1, 1}, {1, 2}, {2, 1},
               {2, 1}, {2, 1}, {2, 1}, {2, 2}, {2, 2}, {2, 1}, {2, 2}, {2, 2},
               {2, 1}, {2, 2}, {2, 1}, {2, 1}, {1, 1}, {2, 1}, {1, 2}, {1, 1},
               {1, 1}, {2, 2}, {2, 2}, {2, 2}, {1, 1}, {2, 1}, {2, 1}, {2, 1},
               {2, 2}, {1, 2}, {1, 2}, {1, 1}, {1, 2}, {1, 2}};

  IC(x, y, mat, mat.size(), mat[0].size());
  IC(nearestValidPoint(x, y, mat));

  return 0;
}
