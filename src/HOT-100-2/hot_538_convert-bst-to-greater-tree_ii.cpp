/**
-- question: 把二叉搜索树转换为累加树
-- method:
 - [ ] 反序中序遍历
 - [*] Morris 遍历
 
--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    TreeNode *convertBST(TreeNode *root) {
        int sum = 0;
        auto node = root;

        while (node) {
            if (!node->right) {
                IC(node->val);
                sum += node->val;
                node->val = sum;
                node = node->left;
            } else {
                auto succ = getSuccessor(node);
                IC(succ->val);
                if (!succ->left) {
                    succ->left = node;
                    node = node->right;
                } else {
                    succ->left = nullptr;
                    IC(sum, node->val);
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
            }
        }

        return root;
    }

private:

    auto getSuccessor(TreeNode *node) -> TreeNode * {
        auto succ = node->right;
        while (succ->left && succ->left != node) succ = succ->left;
        return succ;
    }


    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

//    auto node = new TreeNode(4,
//                             new TreeNode(1),
//                             new TreeNode(6,
//                                          new TreeNode(5),
//                                          new TreeNode(7)
//                             )
//    );

    auto n3 = new TreeNode(3);
    auto n2 = new TreeNode(2);
    n2->right = n3;

    auto n1 = new TreeNode(1, new TreeNode(0), n2);

    auto n8 = new TreeNode(8);
    auto n7 = new TreeNode(7);
    n7->right = n8;

    auto n6 = new TreeNode(6, new TreeNode(5), n7);
    auto root = new TreeNode(4, n1, n6);

    IC(treenode_tools::levelOrder(root));

    auto resNode = solution->convertBST(root);
    IC(treenode_tools::levelOrder(resNode));
    treenode_tools::deleteTreeNode(resNode);

    // code end

    return 0;
}


