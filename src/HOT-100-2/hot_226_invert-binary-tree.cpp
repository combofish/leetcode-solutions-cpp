/**
-- question:
-- method:
 - [ ] 递归
 - [-] 迭代

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

    TreeNode *invertTree(TreeNode *root) {
        if (!root) return nullptr;
        stack<TreeNode *> st;
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

    auto node = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    IC(treenode_tools::levelOrder(node));

    auto result = solution->invertTree(node);

    IC(treenode_tools::levelOrder(result));

    treenode_tools::deleteTreeNode(node);

    // code end

    return 0;
}


