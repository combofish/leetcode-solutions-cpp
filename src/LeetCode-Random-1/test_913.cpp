/**
-- method: bottom_to_up

--result:
执行用时：144 ms, 在所有 C++ 提交中击败了72.08%的用户
内存消耗：75.9 MB, 在所有 C++ 提交中击败了20.13%的用户
通过测试用例：57 / 57
 */

#include "combofish_utils.hpp"
#include <cstring>
#include <tuple>

class Solution {
  const int MOUSE_TURN = 0, CAT_TURN = 1;
  const int MOUSE_WIN = 1;
  const int CAT_WIN = 2;
  const int DRAW = 0;

public:
  mat_t graph;
  tensor_t degress, results;

  int catMouseGame(vector<vector<int>> &graph) {
    int n = graph.size();
    this->graph = graph;
    this->degress = tensor_t(n, mat_t(n, vec_t(2)));
    this->results = tensor_t(n, mat_t(n, vec_t(2)));
    queue<tuple<int, int, int>> qu;

    for (int i = 0; i < n; ++i) {
      for (int j = 1; j < n; ++j) {
        degress[i][j][MOUSE_TURN] = graph[i].size();
        degress[i][j][CAT_TURN] = graph[j].size();
      }
    }

    for (int node : graph[0]) {
      for (int i = 0; i < n; i++) {
        degress[i][node][CAT_TURN]--;
      }
    }

    for (int j = 1; j < n; j++) {
      results[0][j][MOUSE_TURN] = MOUSE_WIN;
      results[0][j][CAT_TURN] = MOUSE_WIN;
      qu.emplace(0, j, MOUSE_TURN);
      qu.emplace(0, j, CAT_TURN);
    }

    for (int i = 1; i < n; ++i) {
      results[i][i][MOUSE_TURN] = CAT_WIN;
      results[i][i][CAT_TURN] = CAT_WIN;
      qu.emplace(i, i, MOUSE_TURN);
      qu.emplace(i, i, CAT_TURN);
    }

    while (!qu.empty()) {
      auto [mouse, cat, turn] = qu.front();
      qu.pop();
      int result = results[mouse][cat][turn];
      vector<tuple<int, int, int>> prevStates = GetPrevStates(mouse, cat, turn);
      for (auto &[prevMouse, prevCat, prevTurn] : prevStates) {
        if (results[prevMouse][prevCat][prevTurn] == DRAW) {
          bool canWin = (result == MOUSE_WIN && prevTurn == MOUSE_TURN) ||
                        (result == CAT_WIN && prevTurn == CAT_TURN);
          if (canWin) {
            results[prevMouse][prevCat][prevTurn] = result;
            qu.emplace(prevMouse, prevCat, prevTurn);
          } else if (--degress[prevMouse][prevCat][prevTurn] == 0) {
            int loseResult = prevTurn == MOUSE_TURN ? CAT_WIN : MOUSE_WIN;
            results[prevMouse][prevCat][prevTurn] = loseResult;
            qu.emplace(prevMouse, prevCat, prevTurn);
          }
        }
      }
    }
    return results[1][2][MOUSE_TURN];
  }

  vector<tuple<int, int, int>> GetPrevStates(int mouse, int cat, int turn) {
    vector<tuple<int, int, int>> prevStates;
    int prevTurn = turn == MOUSE_TURN ? CAT_TURN : MOUSE_TURN;
    if (prevTurn == MOUSE_TURN) {
      for (int &prev : graph[mouse]) {
        prevStates.emplace_back(prev, cat, prevTurn);
      }
    } else {
      for (int &prev : graph[cat]) {
        if (prev != 0) {
          prevStates.emplace_back(mouse, prev, prevTurn);
        }
      }
    }
    return prevStates;
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
  IC(solution->catMouseGame(graph));

  return 0;
}
