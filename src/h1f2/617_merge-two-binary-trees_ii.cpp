/**
-- question: 合并二叉树
-- method:
 - [ ] 深度优先搜索
 - [-] 广度优先搜索

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
        if (root2 == nullptr) return root1;
        queue<TreeNode *> qu;
        qu.push(root1);
        qu.push(root2);

        while (!qu.empty()) {
            auto node1 = qu.front();
            qu.pop();
            auto node2 = qu.front();
            qu.pop();

            node1->val += node2->val;
            if (node1->left != nullptr && node2->left != nullptr) {
                qu.push(node1->left);
                qu.push(node2->left);
            }
            if (node1->right != nullptr && node2->right != nullptr) {
                qu.push(node1->right);
                qu.push(node2->right);
            }

            if (node1->left == nullptr && node2->left != nullptr) {
                node1->left = node2->left;
            }
            if (node1->right == nullptr && node2->right != nullptr) {
                node1->right = node2->right;
            }

        }
        return root1;
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
//    treenode_tools::deleteTreeNode(node1);
    treenode_tools::deleteTreeNode(node2);



    // code end

    return 0;
}