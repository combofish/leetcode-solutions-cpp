/**
-- question: 验证二叉搜索树
-- method:
 - [-] 递归
 - [ ] 中序遍历

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
    bool isValidBST(TreeNode *root) {
        if (!root) return true;

        bool l = isValidBST(root->left);

        if (prev && prev->val >= root->val) return false;
        prev = root;
        auto r = isValidBST(root->right);

        return l && r;
    }

private:

    TreeNode *prev;
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start


    auto n4 = new TreeNode(4, new TreeNode(3), new TreeNode(6));
    auto n5 = new TreeNode(5, new TreeNode(1), n4);

    IC(treenode_tools::levelOrder(n5));


    IC(solution->isValidBST(n5));

    treenode_tools::deleteTreeNode(n5);
    // code end

    return 0;
}
