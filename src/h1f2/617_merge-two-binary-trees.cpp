/**
-- question: 合并二叉树
-- method:
 - [-] 深度优先搜索
 - [ ] 广度优先搜索

--result:

-- analyse:
Time: O( min(m,n) )
Space: O( min(m,n) )
 */

#include "../combofish_utils.hpp"

class Solution {

    // function start.
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr) return root2;
        else if (root2 == nullptr) return root1;
        else {
            auto node = new TreeNode(root1->val + root2->val);
            node->left = mergeTrees(root1->left, root2->left);
            node->right = mergeTrees(root1->right, root2->right);
            return node;
        }
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto node1 = new TreeNode(1, new TreeNode(3), new TreeNode(2));
    auto node2 = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    IC(treenode_tools::levelOrder(node1));
    IC(treenode_tools::levelOrder(node2));


    auto res = solution->mergeTrees(node1, node2);
    IC(treenode_tools::levelOrder(res));

    treenode_tools::deleteTreeNode(res);
    treenode_tools::deleteTreeNode(node1);
    treenode_tools::deleteTreeNode(node2);



    // code end

    return 0;
}