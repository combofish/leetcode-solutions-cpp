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

        vector<int> ans;
        traversal(root, ans);
        return ans;
    }

private:
    void traversal(TreeNode *node, vector<int> &rec) {
        if (!node) return;
        traversal(node->left, rec);
        rec.emplace_back(node->val);
        traversal(node->right, rec);
    }
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
