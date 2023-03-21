/**
-- question: 二叉树中的最大路径和
-- method:
 - [ ] 递归

--result:

-- analyse:
Time: O(N)
Space: O(N)
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <climits>

class Solution {

    // function start.
public:
    int maxPathSum(TreeNode *root) {
        traversal(root);
        return maxSum;
    }

private:
    int maxSum = INT_MIN;

    int traversal(TreeNode *node) {
        if (!node) return 0;
        auto leftMax = std::max(traversal(node->left), 0);
        auto rightMax = std::max(traversal(node->right), 0);

        int priceNewPath = node->val + leftMax + rightMax;
        if (priceNewPath > maxSum) maxSum = priceNewPath;

        return node->val + std::max(leftMax, rightMax);
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto l20 = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    auto l10 = new TreeNode(-10, new TreeNode(9), l20);

    auto root = l10;
    int rel = 42;
    IC(treenode_tools::levelOrder(root));
    IC(solution->maxPathSum(root));
    IC(rel);

    treenode_tools::deleteTreeNode(root);
    // code end

    return 0;
}
