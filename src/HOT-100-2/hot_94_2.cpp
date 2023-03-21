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
    vector<int> inorderTraversal(TreeNode *root) {

        if (!root) return {};

        stack<TreeNode *> st;
        //        st.push(root);

        vector<int> rec;
        while (root || !st.empty()) {
            if (root) {
                st.push(root);
                root = root->left;
            } else {
                auto node = st.top();
                st.pop();

                rec.emplace_back(node->val);
                root = node->right;
            }
        }
        return rec;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto node = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));

    IC(solution->inorderTraversal(node));

    treenode_tools::deleteTreeNode(node);

    // code end

    return 0;
}
