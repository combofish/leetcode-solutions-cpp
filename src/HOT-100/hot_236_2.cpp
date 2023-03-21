/**
-- question: 二叉树的最近公共祖先
-- method:
 - [ ] 递归
 - [*] 存储父节点

--result:

-- analyse:
Time: O(N)
Space: O(N)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    // 所有 Node.val 互不相同 。


    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        cache.clear();
        visited.clear();
        cache[root->val] = nullptr;
        traversal(root);

        IC(visited);
        IC(cache);

        while (p != nullptr) {
            visited[p->val] = true;
            p = cache[p->val];
        }
        IC();
        IC(visited);
        IC(cache);

        while (q) {
            if (visited[q->val]) return q;
            q = cache[q->val];
        }


        return nullptr;
    }


private:
    unordered_map<int, TreeNode *> cache;
    unordered_map<int, bool> visited;

    void traversal(TreeNode *node) {
        if (node->left) {
            cache[node->left->val] = node;
            traversal(node->left);
        }
        if (node->right) {
            cache[node->right->val] = node;
            traversal(node->right);
        }
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto ll4 = new TreeNode(4);
    auto ll2 = new TreeNode(2, new TreeNode(7), ll4);
    auto ll5 = new TreeNode(5, new TreeNode(6), ll2);
    auto ll1 = new TreeNode(1, new TreeNode(0), new TreeNode(8));
    auto ll3 = new TreeNode(3, ll5, ll1);

    auto root = ll3;
    auto result = solution->lowestCommonAncestor(root, ll5, ll4);

    int rel = 5;
    IC(rel);
    IC(result->val);
    IC(treenode_tools::levelOrder(root));
    treenode_tools::deleteTreeNode(root);
    // code end

    return 0;
}
