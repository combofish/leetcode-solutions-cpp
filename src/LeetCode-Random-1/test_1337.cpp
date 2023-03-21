/**
-- method: pair,rec,sort

--result:
执行用时：12 ms, 在所有 C++ 提交中击败了55.04%的用户
内存消耗：10.1 MB, 在所有 C++ 提交中击败了91.82%的用户
通过测试用例：52 / 52
 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <utility>
vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
  int m = mat.size(), n = mat[0].size();
  vector<pair<int, int>> rec(m); // (idx, count)

  for (int i = 0; i < m; ++i) {
    int count = 0;
    for (const int &p : mat[i])
      if (p == 1)
        ++count;
      else
        break;

    rec[i] = std::make_pair(i, count);
  }

  IC(rec);
  std::sort(rec.begin(), rec.end(),
            [](const pair<int, int> &p1, const pair<int, int> &p2) {
              if (p1.second == p2.second) {
                return p1.first < p2.first;
              } else {
                return p1.second < p2.second;
              }
            });

  IC('s', rec);

  vec_t res(k);
  for (int j = 0; j < k; ++j) {
    res[j] = rec[j].first;
  }

  return res;
}

int main() {
  // code start

  mat_t mat = {{1, 1, 0, 0, 0},
               {1, 1, 1, 1, 0},
               {1, 0, 0, 0, 0},
               {1, 1, 0, 0, 0},
               {1, 1, 1, 1, 1}};

  int k = 3;
  IC(mat, k);
  IC(kWeakestRows(mat, k));
  return 0;
}
