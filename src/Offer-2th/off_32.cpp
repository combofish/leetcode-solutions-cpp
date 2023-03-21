/**
-- question: 从上到下打印二叉树
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
    vector<int> levelOrder(TreeNode *root) {
        if (!root) return {};
        auto qu = queue<TreeNode *>();
        qu.push(root);

        auto result = vector<int>();
        while (!qu.empty()) {
            auto node = qu.front();
            qu.pop();

            result.emplace_back(node->val);
            if (node->left) qu.push(node->left);
            if (node->right) qu.push(node->right);
        }
        return result;
    }

private:
    // function end.
};


int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto n20 = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    auto n3 = new TreeNode(3, new TreeNode(9), n20);

    auto root = n3;

    vector<int> rel = {3, 9, 20, 15, 7};
    IC(rel);
    IC(solution->levelOrder(root));

    treenode_tools::deleteTreeNode(root);
    // code end

    return 0;
}
