/**
-- method: 迭代

--result: not understand


-- analyse:
Time: O(n)
Space: O(1)

 */

#include "combofish_utils.hpp"

class Solution {
public:
  // function start.
  TreeNode *deleteNode(TreeNode *root, int key) {
    TreeNode *cur = root, *curParent = nullptr;
    while (cur && cur->val != key) {
      curParent = cur;
      if (cur->val > key) {
        cur = cur->left;
      } else {
        cur = cur->right;
      }
    }

    if (!cur)
      return root;
    if (!cur->left && !cur->right) {
      cur = nullptr;
    } else if (!cur->right) {
      cur = cur->left;
    } else if (!cur->right) {
      cur = cur->right;
    } else {
      TreeNode *successor = cur->right, *successorParent = cur;
      while (successor->left) {
        successorParent = successor;
        successor = successor->left;
      }
      if (successorParent->val == cur->val) {
        successorParent->right = successor->right;
      } else {
        successorParent->left = successor->right;
      }
      successor->right = cur->right;
      successor->left = cur->left;
      cur = successor;
    }
    if (!curParent) {
      return cur;
    } else {
      if (curParent->left && curParent->left->val == key) {
        curParent->left = cur;
      } else {
        curParent->right = cur;
      }
      return root;
    }
  }

  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start

  TreeNode *p1 = new TreeNode(3, new TreeNode(2), new TreeNode(4));
  TreeNode *p2 = new TreeNode(6, nullptr, new TreeNode(7));
  TreeNode *root = new TreeNode(5, p1, p2);

  posterOrder(root);
  out_line();
  middleOrder(root);
  out_line();
  hindOrder(root);
  out_line();

  int key = 3;
  IC(solution->deleteNode(root, key));
  return 0;
}
