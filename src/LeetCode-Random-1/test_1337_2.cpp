/**
-- method: vec, idxs, step, add.

--result:
执行用时：12 ms, 在所有 C++ 提交中击败了55.04%的用户
内存消耗：10.3 MB, 在所有 C++ 提交中击败了31.58%的用户
通过测试用例：52 / 52
 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <utility>

vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
  int m = mat.size(), n = mat[0].size();

  vec_t idxs(m);
  for (int i = 0; i < m; ++i)
    idxs[i] = i;

  vec_t res;

  int step = 0;

  while (res.size() < k && step < n) {
    vec_t rec; // record idx;

    for (const int &i : idxs)
      if (mat[i][step] == 0)
        rec.emplace_back(i);

    IC(rec);

    if (!rec.empty()) {
      // rec is ordered;
      for (int j = 0; j < rec.size(); j++) {
        res.emplace_back(rec[j]);
        if (res.size() == k)
          return res;

        for (int q = 0; q < idxs.size(); ++q)
          if (idxs[q] == rec[j])
            idxs.erase(idxs.begin() + q);
      }

      // std::for_each(rec.rbegin(), rec.rend(),
      //               [&idxs](const int &i) { idxs.erase(idxs.begin() + i); });
    }

    IC(step, rec, idxs, res);

    ++step;
  }

  IC(res.size(), idxs, k - res.size());

  int ind = k - res.size();
  for (int p = 0; p < ind; ++p) {
    IC(p);
    res.emplace_back(idxs[p]);
  }

  IC(res.size(), idxs);
  return res;
}

int main() {
  // code start

  // mat_t mat = {{1, 1, 0, 0, 0},
  //              {1, 1, 1, 1, 0},
  //              {1, 0, 0, 0, 0},
  //              {1, 1, 0, 0, 0},
  //              {1, 1, 1, 1, 1}};

  //  mat_t mat = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};

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
