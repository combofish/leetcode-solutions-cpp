/**
-- question: 二叉树的最近公共祖先
-- method:
 - [-] 递归
 - [ ] 存储父节点

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        traversal(root, p, q);
        return ans;
    }

private:
    TreeNode *ans;

    bool traversal(TreeNode *node, TreeNode *p, TreeNode *q) {
        if (!node) return false;
        auto lson = traversal(node->left, p, q);
        auto rson = traversal(node->right, p, q);

        if ((lson && rson) || ((node->val == p->val || node->val == q->val) && (lson || rson)))
            ans = node;

        return lson || rson || (node->val == p->val || node->val == q->val);

    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto n1 = new TreeNode(1);
    auto n8 = new TreeNode(8);

    auto root = new TreeNode(3, n1, new TreeNode(4, nullptr, n8));
    IC(treenode_tools::levelOrder(root));

    auto p = n1;
    auto q = n8;

    int ans = 3;
    IC(ans);
    IC(solution->lowestCommonAncestor(root, p, q)->val);

    treenode_tools::deleteTreeNode(root);


    // code end

    return 0;
}


