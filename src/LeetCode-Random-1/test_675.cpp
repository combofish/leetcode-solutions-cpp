/**
-- method: 广度优先搜索

--result:
执行用时：636 ms, 在所有 C++ 提交中击败了45.75%的用户
内存消耗：95.6 MB, 在所有 C++ 提交中击败了54.79%的用户
通过测试用例：54 / 54

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <atomic>
// #include <pthread.h>
#include <vector>

class Solution {
  int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  int m, n;

  int bfs(mat_t &forest, int sx, int sy, int tx, int ty) {
    if (sx == tx && sy == ty) {
      return 0;
    }

    int step = 0;
    queue<pair<int, int>> qu;
    vector<vector<bool>> used(m, vector<bool>(n, false));
    qu.emplace(sx, sy);
    used[sx][sy] = true;
    while (!qu.empty()) {
      step++;
      int sz = qu.size();
      for (int i = 0; i < sz; ++i) {
        auto [cx, cy] = qu.front();
        qu.pop();
        for (int k = 0; k < 4; k++) {
          int nx = cx + dirs[k][0], ny = cy + dirs[k][1];
          if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (!used[nx][ny] && forest[nx][ny] > 0) {
              if (nx == tx && ny == ty) {
                return step;
              }
              qu.emplace(nx, ny);
              used[nx][ny] = true;
            }
          }
        }
      }
    }
    return -1;
  }

public:
  // function start.
  int cutOffTree(vector<vector<int>> &forest) {
    vector<pair<int, int>> trees;
    trees.clear();

    m = forest.size();
    n = forest[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (forest[i][j] > 1) {
          trees.emplace_back(i, j);
        }
      }
    }

    std::sort(trees.begin(), trees.end(),
              [&](const pair<int, int> &a, const pair<int, int> &b) {
                return forest[a.first][a.second] < forest[b.first][b.second];
              });

    int cx = 0;
    int cy = 0;
    int ans = 0;
    for (int i = 0; i < trees.size(); ++i) {
      int steps = bfs(forest, cx, cy, trees[i].first, trees[i].second);
      if (steps == -1)
        return -1;

      ans += steps;
      cx = trees[i].first;
      cy = trees[i].second;
    }

    return ans;
  }

  // function end.
};

int main() {

  Solution *solution = new Solution();

  cout << endl;
  mat_t forest3 = {{2, 3, 4}, {0, 0, 6}, {8, 7, 5}};
  IC(forest3);
  IC(solution->cutOffTree(forest3));
  IC(8);

  // code start
  mat_t forest = {{1, 2, 3}, {0, 0, 4}, {7, 6, 5}};
  IC(forest);
  IC(solution->cutOffTree(forest));
  IC(6);

  cout << endl;
  mat_t forest2 = {{2, 3, 4}, {0, 0, 5}, {8, 7, 6}};
  IC(forest2);
  IC(solution->cutOffTree(forest2));
  IC(6);

  return 0;
}
