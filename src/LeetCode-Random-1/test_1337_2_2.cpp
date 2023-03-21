/**
-- method: vec_bool used, step, add.

--result:
执行用时：16 ms, 在所有 C++ 提交中击败了11.70%的用户
内存消耗：10.3 MB, 在所有 C++ 提交中击败了23.05%的用户
通过测试用例：52 / 52
 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <utility>

vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
  int m = mat.size(), n = mat[0].size();

  vector<bool> used(m, false);
  vec_t res;

  int step = 0;

  while (res.size() < k && step < n) {
    vec_t rec; // record idx;

    for (int i = 0; i < m; ++i) {
      if (used[i])
        continue;

      if (mat[i][step] == 0)
        rec.emplace_back(i);
    }

    IC(rec);

    if (!rec.empty()) {
      // rec is ordered;
      for (int j = 0; j < rec.size(); j++) {
        res.emplace_back(rec[j]);
        used[rec[j]] = true;

        if (res.size() == k)
          return res;
      }

      // std::for_each(rec.rbegin(), rec.rend(),
      //               [&idxs](const int &i) { idxs.erase(idxs.begin() + i); });
    }

    IC(step, rec, used, res);

    ++step;
  }

  IC(res.size(), used, k - res.size());

  for (int i = 0; i < m; i++) {
    if (!used[i] && res.size() < k) {

      res.emplace_back(i);
      used[i] = true;

      IC(i, used, res.size());
    }
  }

  IC(res.size(), used);
  return res;
}

int main() {
  // code start

  // mat_t mat = {{1, 1, 0, 0, 0},
  //              {1, 1, 1, 1, 0},
  //              {1, 0, 0, 0, 0},
  //              {1, 1, 0, 0, 0},
  //              {1, 1, 1, 1, 1}};

  //  mat_t mat = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1,
  //  1}};

  // mat_t mat = {{1, 1, 1, 0, 0, 0, 0},
  //              {1, 1, 1, 1, 1, 1, 0},
  //              {0, 0, 0, 0, 0, 0, 0},
  //              {1, 1, 1, 0, 0, 0, 0},
  //              {1, 1, 1, 1, 1, 1, 1}};

  mat_t mat = {{1, 1, 0}, {1, 1, 0}, {1, 1, 1}, {1, 1, 1},
               {0, 0, 0}, {1, 1, 1}, {1, 0, 0}};
  int k = 6;
  IC(mat, k);
  IC(kWeakestRows(mat, k));
  return 0;
}
