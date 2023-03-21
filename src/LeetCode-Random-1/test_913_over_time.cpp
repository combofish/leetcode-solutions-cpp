/**
-- method:

--result:

 */

#include "combofish_utils.hpp"
#include <cstring>

const int MOUSE_WIN = 1;
const int CAT_WIN = 2;
const int DRAW = 0;
const int MAXN = 51;

class Solution {
public:
  int n;
  int dp[MAXN][MAXN][MAXN * (MAXN - 1)];
  mat_t graph;

  int catMouseGame(vector<vector<int>> &graph) {
    this->graph = graph;
    this->n = graph.size();
    memset(dp, -1, sizeof(dp));
    return getResult(1, 2, 0);
  }

  int getResult(int mouse, int cat, int turns) {
    // IC(mouse, cat, turns);

    if (turns == 2 * n * (n - 1))
      return DRAW;

    if (dp[mouse][cat][turns] < 0) {
      if (mouse == 0)
        dp[mouse][cat][turns] = MOUSE_WIN;
      else if (cat == mouse)
        dp[mouse][cat][turns] = CAT_WIN;
      else
        getNextResult(mouse, cat, turns);
    }
    return dp[mouse][cat][turns];
    // return IC(dp[mouse][cat][turns]);
  }

  void getNextResult(int mouse, int cat, int turns) {
    int curMove = turns % 2 == 0 ? mouse : cat;
    int defaultResult = curMove == mouse ? CAT_WIN : MOUSE_WIN;
    int result = defaultResult;
    for (int next : graph[curMove]) {
      if (curMove == cat && next == 0)
        continue;

      int nextMouse = curMove == mouse ? next : mouse;
      int nextCat = curMove == cat ? next : cat;
      int nextResult = getResult(nextMouse, nextCat, turns + 1);
      if (nextResult != defaultResult) {
        result = nextResult;
        if (result != DRAW) {
          break;
        }
      }
    }
    dp[mouse][cat][turns] = result;
  }
};

int main() {
  // code start
  mat_t graph = {{9, 16, 17, 29, 32, 43},
                 {12, 16, 20, 32, 48},
                 {8, 12, 16, 21, 24, 43, 45, 46},
                 {8, 10, 16, 27},
                 {5, 8, 10, 13, 21, 25, 26, 37, 48},
                 {4, 7, 12, 23, 28, 33, 35, 48},
                 {10, 20, 22, 25, 26, 31, 45, 46, 47},
                 {5, 10},
                 {2, 3, 4, 30, 41},
                 {0, 17, 29},
                 {3, 4, 6, 7, 21, 23, 25, 29, 38},
                 {22, 35, 41},
                 {1, 2, 5, 17, 19, 22, 28, 31, 44},
                 {4, 15, 16, 23, 33, 39, 40, 44, 49},
                 {19, 23, 24, 26, 27, 34, 45, 46, 47},
                 {13, 26, 31, 32, 37, 44, 45},
                 {0, 1, 2, 3, 13, 32, 34, 49},
                 {0, 9, 12, 19, 20, 32, 36},
                 {38},
                 {12, 14, 17, 21, 30, 42},
                 {1, 6, 17, 21, 23, 36, 38, 45},
                 {2, 4, 10, 19, 20, 31, 45, 47},
                 {6, 11, 12, 25, 26, 27, 48},
                 {5, 10, 13, 14, 20, 44, 48},
                 {2, 14, 26, 29, 34},
                 {4, 6, 10, 22, 30, 40, 47},
                 {4, 6, 14, 15, 22, 24, 30, 43, 49},
                 {3, 14, 22, 34, 35, 43, 44},
                 {5, 12, 43, 48},
                 {0, 9, 10, 24, 33, 47},
                 {8, 19, 25, 26, 37, 40, 42, 48},
                 {6, 12, 15, 21, 37, 39, 42, 44, 49},
                 {0, 1, 15, 16, 17, 49},
                 {5, 13, 29, 35, 43, 47},
                 {14, 16, 24, 27, 36, 38},
                 {5, 11, 27, 33, 42, 48},
                 {17, 20, 34, 40},
                 {4, 15, 30, 31, 45, 46},
                 {10, 18, 20, 34},
                 {13, 31, 40},
                 {13, 25, 30, 36, 39, 41, 42, 46, 47},
                 {8, 11, 40, 43, 45},
                 {19, 30, 31, 35, 40},
                 {0, 2, 26, 27, 28, 33, 41},
                 {12, 13, 15, 23, 27, 31, 49},
                 {2, 6, 14, 15, 20, 21, 37, 41, 46, 49},
                 {2, 6, 14, 37, 40, 45},
                 {6, 14, 21, 25, 29, 33, 40},
                 {1, 4, 5, 22, 23, 28, 30, 35},
                 {13, 16, 26, 31, 32, 44, 45}};

  // {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}};

  IC(graph.size());

  Solution *solution = new Solution();
  IC(solution->catMouseGame(graph) == 1);

  return 0;
}
