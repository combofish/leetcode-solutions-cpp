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
    bool isSymmetric(TreeNode *root) {

        return isS(root->left, root->right);
    }

private:
    bool isS(TreeNode *ln, TreeNode *rn) {
        // if (ln && !rn) return false;
        // if (!ln && rn) return false;

        if (!ln && !rn) return true;
        else if (ln && rn)
            return ln->val == rn->val && isS(ln->left, rn->right) && isS(ln->right, rn->left);
        else
            return false;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto node = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    bool ans = true;

    IC(treenode_tools::levelOrder(node));
    IC(ans);

    IC(solution->isSymmetric(node));
    treenode_tools::deleteTreeNode(node);

    // code end

    return 0;
}
