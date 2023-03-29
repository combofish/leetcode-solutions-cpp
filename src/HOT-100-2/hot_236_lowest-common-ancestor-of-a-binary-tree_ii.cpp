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
        fa[root->val] = nullptr;
        traversal(root);

        while (p) {
            vis[p->val] = true;
            p = fa[p->val];
        }

        while (q) {
            if (vis[q->val]) return q;
            q = fa[q->val];
        }
        return nullptr;

    }

private:
    unordered_map<int, TreeNode *> fa;
    unordered_map<int, bool> vis;

    void traversal(TreeNode *node) {
        if (node->left) {
            fa[node->left->val] = node;
            traversal(node->left);
        }
        if (node->right) {
            fa[node->right->val] = node;
            traversal(node->right);
        }
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


