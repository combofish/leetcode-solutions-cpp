/**
-- method: record

--result:
执行用时：4 ms, 在所有 C++ 提交中击败了80.84%的用户
内存消耗：16.3 MB, 在所有 C++ 提交中击败了28.50%的用户
通过测试用例：63 / 63

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <cstdlib>

class Solution {
  int record(TreeNode *p, int n) {
    if (p == nullptr)
      return n;

    IC(n << 1, p->val);
    n = (n << 1) + p->val;
    IC(n);
    out_line();

    if (p->left == nullptr && p->right == nullptr) {
      return n;
    }

    int ret = 0;
    if (p->left != nullptr)
      ret += record(p->left, n);
    if (p->right != nullptr)
      ret += record(p->right, n);
    return ret;
  }

public:
  // function start.
  int sumRootToLeaf(TreeNode *root) {
    int ret = record(root, 0);

    return ret;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  TreeNode *p1 = new TreeNode(0, new TreeNode(0), new TreeNode(1));
  TreeNode *p2 = new TreeNode(1, new TreeNode(0), new TreeNode(1));
  TreeNode *p3 = new TreeNode(1, p1, p2);
  IC(solution->sumRootToLeaf(p3));
  IC(22);
  return 0;
}
