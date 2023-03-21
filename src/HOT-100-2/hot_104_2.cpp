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
    int maxDepth(TreeNode *root) {
        if (!root) return 0;

        auto l = maxDepth(root->left);
        auto r = maxDepth(root->right);

        return std::max(l, r) + 1;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto node = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    IC(treenode_tools::levelOrder(node));
    int res = 3;
    IC(res);

    IC(solution->maxDepth(node));

    treenode_tools::deleteTreeNode(node);
    // code end

    return 0;
}
