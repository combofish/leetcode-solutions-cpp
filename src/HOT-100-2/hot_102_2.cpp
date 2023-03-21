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
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root) return {};
        result.clear();
        traversal(root, 0);
        return result;
    }

private:
    vector<vector<int>> result;

    void traversal(TreeNode *node, int idx) {
        IC(result, idx);
        if (result.size() == idx) {
            result.emplace_back(vector<int>());
        }

        result[idx].emplace_back(node->val);

        if (node->left) traversal(node->left, idx + 1);
        if (node->right) traversal(node->right, idx + 1);
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto node = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    IC(treenode_tools::levelOrder(node));

    vector<vector<int>> res = {{3}, {9, 20}, {15, 7}};
    IC(res);

    IC(solution->levelOrder(node));

    treenode_tools::deleteTreeNode(node);


    // code end

    return 0;
}
