/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int diameterOfBinaryTree(TreeNode *root) {
        if (!root) return 0;
        ans = 0;
        traversal(root);
        return ans - 1;
    }

private:
    int ans;

    int traversal(TreeNode *node) {
        if (!node) return 0;
        auto l = traversal(node->left);
        auto r = traversal(node->right);

        ans = std::max(ans, r + l + 1);
        return 1 + std::max(l, r);
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto tmp = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    auto node = new TreeNode(1, tmp, new TreeNode(3));

    IC(treenode_tools::levelOrder(node));

    int ans = 3;
    IC(ans);

    IC(solution->diameterOfBinaryTree(node));


    treenode_tools::deleteTreeNode(node);

    // code end

    return 0;
}


