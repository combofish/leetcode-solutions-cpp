/**
-- question: 二叉树中的最大路径和
-- method:
 - [ ] 递归

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
    int maxPathSum(TreeNode *root) {
        // root != nullptr;
        if (root == nullptr) return 0;

        ans = root->val;
        traversal(root);
        return ans;
    }

private:
    int ans;

    int traversal(TreeNode *node) {
        if (!node) return 0;

        auto l = std::max(0, traversal(node->left)); // 不记小于 0 的。
        auto r = std::max(0, traversal(node->right));

        ans = std::max(ans, l + r + node->val);
        return std::max(l, r) + node->val;
    }


    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto n20 = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    auto root = new TreeNode(-10, new TreeNode(9), n20);

    int ans = 42;
    IC(ans);
    IC(treenode_tools::levelOrder(root));
    IC(solution->maxPathSum(root));

    treenode_tools::deleteTreeNode(root);


    // code end

    return 0;
}
