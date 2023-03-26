/**
-- question:
-- method:
 - [-] 递归
 - [ ] 迭代

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

    TreeNode *invertTree(TreeNode *root) {
        if (!root) return nullptr;

        std::swap(root->right, root->left);

        invertTree(root->right);
        invertTree(root->left);

        return root;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto node = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    IC(treenode_tools::levelOrder(node));

    auto result = solution->invertTree(node);

    IC(treenode_tools::levelOrder(result));

    treenode_tools::deleteTreeNode(node);

    // code end

    return 0;
}


