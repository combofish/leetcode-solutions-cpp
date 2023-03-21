/**
-- question: 二叉树的最近公共祖先
-- method:
 - [ ] 递归
 - [ ] 存储父节点 recursive
 - [*] 存储父节点 iteration

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
        unordered_map<int, TreeNode *> getRoot;
        unordered_map<int, bool> visited;

        auto st = stack<TreeNode *>();
        getRoot[root->val] = nullptr;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            if (node->left) {
                getRoot[node->left->val] = node;
                st.push(node->left);
            }
            if (node->right) {
                getRoot[node->right->val] = node;
                st.push(node->right);
            }
        }

        while (p) {
            visited[p->val] = true;
            p = getRoot[p->val];
        }

        while (q) {
            if (visited[q->val]) return q;
            q = getRoot[q->val];
        }

        return nullptr;
    }


private:
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
