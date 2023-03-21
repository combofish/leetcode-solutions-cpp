/**
-- method: fs

--result:
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：9.5 MB, 在所有 C++ 提交中击败了81.06%的用户
通过测试用例：72 / 72

-- analyse:
Time: O(n)
Space: O(n)

 */

#include "combofish_utils.hpp"

class Solution {
  int n;
  bool fs(TreeNode *p) {

    if (p == nullptr) {
      return true;
    }

    if (p->val == n) {
      return fs(p->left) && fs(p->right);
    } else {
      return false;
    }
  }

public:
  // function start.
  bool isUnivalTree(TreeNode *root) {
    n = root->val;
    return fs(root);
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  TreeNode *p1 = new TreeNode(2, new TreeNode(5), new TreeNode(2));
  TreeNode *p2 = new TreeNode(2, p1, new TreeNode(2));

  IC(solution->isUnivalTree(p2));
  IC(false);

  return 0;
}
