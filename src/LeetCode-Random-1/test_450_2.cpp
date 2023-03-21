/**
-- method: 递归

--result:
执行用时：24 ms, 在所有 C++ 提交中击败了95.21%的用户
内存消耗：31.9 MB, 在所有 C++ 提交中击败了31.17%的用户
通过测试用例：91 / 91

-- analyse:
Time: O(n)
Space: O(n)

 */

#include "combofish_utils.hpp"

class Solution {
public:
  // function start.
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr)
      return nullptr;

    if (root->val > key) {
      root->left = deleteNode(root->left, key);
      return root;
    }

    if (root->val < key) {
      root->right = deleteNode(root->right, key);
      return root;
    }

    if (root->val == key) {
      if (!root->left && !root->right)
        return nullptr;

      if (!root->right)
        return root->left;
      if (!root->right)
        return root->right;

      TreeNode *successor = root->right;
      while (successor->left)
        successor = successor->left;

      root->right = deleteNode(root->right, successor->val);
      successor->right = root->right;
      successor->left = root->left;
      return successor;
    }

    return root;
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
