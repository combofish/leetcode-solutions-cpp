/**
-- question: 打家劫舍 III
-- method:
 - [*] dp

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
    int rob(TreeNode *root) {
        auto res = traversal(root);
        return std::max(res.first, res.second);
    }

private:
    std::pair<int, int> traversal(TreeNode *node) {
        if (!node) return {0, 0};
        auto lVal = traversal(node->left);
        auto rVal = traversal(node->right);

        // pair<not rob, rob>
        auto robThis = node->val + lVal.first + rVal.first;
        auto notRobThis = std::max(lVal.second, lVal.first) + std::max(rVal.second, rVal.second);
        return {notRobThis, robThis};
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto l2 = new TreeNode(2, nullptr, new TreeNode(3));
    auto l3 = new TreeNode(3, nullptr, new TreeNode(1));
    auto root = new TreeNode(3, l2, l3);

    int rel = 7;
    IC(rel);
    IC(treenode_tools::levelOrder(root));
    IC(solution->rob(root));
    treenode_tools::deleteTreeNode(root);
    // code end

    return 0;
}
