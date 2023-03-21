/**
-- question: 二叉树的最近公共祖先
-- method:
 - [*] 递归
 - [ ] 存储父节点

--result:

-- analyse:
Time: O(N)
Space: O(N)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || root == p || root == q) return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);

        // if (!left && !right) return nullptr;
        // else if (!left)
        //     return right;
        // else if (!right)
        //     return left;
        // return root;// left != nullptr && right != nullptr;

        if (!right) return left;
        else if (!left)
            return right;
        else
            return root; 
    }


private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto ll4 = new TreeNode(4);
    auto ll2 = new TreeNode(2, new TreeNode(7), ll4);
    auto ll5 = new TreeNode(5, new TreeNode(6), ll2);
    auto ll1 = new TreeNode(1, new TreeNode(0), new TreeNode(8));
    auto ll3 = new TreeNode(3, ll5, ll1);

    auto root = ll3;
    auto result = solution->lowestCommonAncestor(root, ll5, ll4);

    int rel = 5;
    IC(rel);
    IC(result->val);
    IC(treenode_tools::levelOrder(root));
    treenode_tools::deleteTreeNode(root);
    // code end

    return 0;
}
