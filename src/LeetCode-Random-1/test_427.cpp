/**
 * OVer time
 */
#include "combofish_utils.hpp"
#include <functional>

class Node {
public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;
  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }
  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }
  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight,
       Node *_bottomLeft, Node *_bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

Node *construct(mat_t &grid) {
  std::function<Node *(int, int, int, int)> dfs;

  dfs = [&](int r0, int c0, int r1, int c1) {
    for (int i = r0; i < r1; ++i)
      for (int j = c0; j < c1; ++j)
        if (grid[i][j] != grid[r0][c0])
          return new Node(true, false,
                          dfs(r0, c0, (r0 + r1) / 2, (c0 + c1) / 2),
                          dfs(r0, (c0 + c1) / 2, (r0 + r1) / 2, c1),
                          dfs((r0 + r1) / 2, c0, r1, (c0 + c1) / 2),
                          dfs((r0 + r1) / 2, (c0 + c1) / 2, r1, c1));

    return new Node(grid[r0][c0], true);
  };

  return dfs(0, 0, grid.size(), grid.size());
}
int use() { return 0; }
int main(int argc, char **argv) {
  vector<vector<int>> grid = {{0, 1}, {1, 0}};

  Node *n = construct(grid);

  return 0;
}
