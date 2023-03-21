/**
-- question: 对称的二叉树
-- method:
 - [ ] recursive
 - [*] iterate
 
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
    bool isSymmetric(TreeNode *root) {

        if (!root) return true;
        auto qu = queue<TreeNode *>();
        qu.push(root->left);
        qu.push(root->right);

        while (!qu.empty()) {
            auto left = qu.front();
            qu.pop();
            auto right = qu.front();
            qu.pop();
            if (!left && !right) continue;
            else if (!left && right)
                return false;
            else if (left && !right)
                return false;
            else if (left->val != right->val)
                return false;
            else {
                qu.push(left->left);
                qu.push(right->right);

                qu.push(left->right);
                qu.push(right->left);
            }
        }
        return true;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto l2 = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    auto ll2 = new TreeNode(2, new TreeNode(4), new TreeNode(3));
    auto root = new TreeNode(1, l2, ll2);
    bool rel = true;

    IC(treenode_tools::levelOrder(root));
    IC(rel);
    IC(solution->isSymmetric(root));

    treenode_tools::deleteTreeNode(root);


    // code end

    return 0;
}
