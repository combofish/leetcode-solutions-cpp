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

        vector<vector<int>> ans;
        queue<TreeNode *> qu;
        qu.push(root);

        while (!qu.empty()) {
            int sz = qu.size();
            vector<int> tmp;
            while (sz--) {
                auto node = qu.front();
                qu.pop();
                tmp.emplace_back(node->val);

                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }
            ans.emplace_back(tmp);
        }

        return ans;
    }

private:
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
