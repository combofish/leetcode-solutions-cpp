/**
-- question: 翻转二叉树
-- method:
 - [ ] recursive
 - [*] iterate
 
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
    TreeNode *invertTree(TreeNode *root) {
        if (!root) return root;

        auto st = stack<TreeNode *>();
        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            st.pop();

            std::swap(node->left, node->right);
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }

        return root;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> root = {4, 2, 7, 1, 3, 6, 9};
    auto rel = {4, 7, 2, 9, 6, 3, 1};
    IC(root, rel);

    auto ll2 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    auto ll7 = new TreeNode(7, new TreeNode(6), new TreeNode(9));
    auto ll4 = new TreeNode(4, ll2, ll7);

    IC(treenode_tools::levelOrder(ll4));

    auto result = solution->invertTree(ll4);

    IC(treenode_tools::levelOrder(result));
    treenode_tools::deleteTreeNode(result);

    // code end

    return 0;
}
