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
#include <sys/types.h>

class Solution {

    // function start.
public:
    TreeNode *convertBST(TreeNode *root) {
        int val = 0;
        auto node = root;
        while (node) {
            if (!node->right) {
                val += node->val;
                node->val = val;
                node = node->left;
            } else {
                auto succ = getSuccessor(node);
                if (succ->left) {
                    succ->left = node;
                    node = node->right;
                } else {
                    succ->left = nullptr;
                    val += node->val;
                    node->val = val;
                    node = node->left;
                }
            }
        }
        return root;
    }

private:
    TreeNode *getSuccessor(TreeNode *node) {
        auto succ = node->right;
        while (succ->left && succ->left != node) {
            succ = succ->left;
        }
        return succ;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto node = new TreeNode(4, new TreeNode(1), new TreeNode(6));

    auto result = solution->convertBST(node);
    auto l_result = treenode_tools::levelOrder(result);
    IC(l_result);
    treenode_tools::deleteTreeNode(result);

    // code end

    return 0;
}
