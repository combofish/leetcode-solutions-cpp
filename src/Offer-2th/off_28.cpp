/**
-- question: 对称的二叉树
-- method:
 - [*] recursive
 - [ ] iterate
 
--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return traversal(root->left, root->right);
    }

private:
    bool traversal(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        else if (!left && right)
            return false;
        else if (left && !right)
            return false;
        else if (left->val != right->val)
            return false;
        else
            return traversal(left->left, right->right) && traversal(left->right, right->left);
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto l2 = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    auto ll2 = new TreeNode(2, new TreeNode(4), new TreeNode(3));
    auto root = new TreeNode(1, l2, ll2);
    bool rel = true;

    IC(treenode_tools::levelOrder(root));
    IC(rel);
    IC(solution->isSymmetric(root));

    treenode_tools::deleteTreeNode(root);


    // code end

    return 0;
}
