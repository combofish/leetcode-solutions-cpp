/**
-- method: 中序遍历

--result:
执行用时：24 ms, 在所有 C++ 提交中击败了89.09%的用户
内存消耗：22.3 MB, 在所有 C++ 提交中击败了67.27%的用户
通过测试用例：24 / 24

-- analyse:
Time: O(n)
Space: O(n)

 */

#include "combofish_utils.hpp"
#include <ios>

void out_st(stack<TreeNode *> ot) {
  IC(ot.size());
  while (!ot.empty()) {
    IC(ot.top()->val);
    ot.pop();
  }
}

class Solution {
public:
  TreeNode *_inorderSuccessor(TreeNode *root, TreeNode *p) {
    stack<TreeNode *> st;
    TreeNode *prev = nullptr, *curr = root;
    while (!st.empty() || curr != nullptr) {
      while (curr != nullptr) {
        IC('i', curr);

        st.emplace(curr);
        curr = curr->left;
      }
      curr = st.top();
      st.pop();

      // IC(curr == root->left);
      IC(p, prev, curr);
      if (curr != nullptr)
        IC(curr->val);

      if (prev == p) {
        return curr;
      }
      prev = curr;
      curr = curr->right;
    }
    return nullptr;
  }
};

int main() {

  Solution *solution = new Solution();
  IC(2562);
  // code start
  TreeNode *p1 = new TreeNode(1);
  TreeNode *p2 = new TreeNode(2, p1, nullptr);
  TreeNode *p4 = new TreeNode(4);
  TreeNode *p3 = new TreeNode(3, p2, p4);

  TreeNode *p6 = new TreeNode(6);
  TreeNode *p5 = new TreeNode(5, p3, p6);
  TreeNode *root = p5;
  TreeNode *p = p6;

  IC(p1, p2, p3, p4, p5, p6);

  TreeNode *res = solution->_inorderSuccessor(root, p);
  if (res != nullptr)
    IC(res->val, res == nullptr);
  else
    IC(res, res == nullptr);

  IC(2);

  return 0;
}
