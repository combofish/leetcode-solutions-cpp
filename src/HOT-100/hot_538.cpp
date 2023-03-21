/**
-- question: 把二叉搜索树转换为累加树
-- method:
 - [*] 反序中序遍历
 - [ ] Morris 遍历
 
--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    TreeNode *convertBST(TreeNode *root) {
        int sum = 0;
        traversal(root, sum);
        return root;
    }

private:
    void traversal(TreeNode *node, int &val) {
        if (!node) return;
	IC(node->val);

        traversal(node->right, val);
        val += node->val;
        node->val = val;
        traversal(node->left, val);
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
