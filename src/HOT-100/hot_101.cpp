/**
-- question: 对称二叉树
-- method:
 - [*] 递归
 - [ ] stack
 - [ ] queue


--result:

-- analyse:
Time: O()
Space: O()
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    bool isSymmetric(TreeNode *root) {
        return traversal(root->left, root->right);
    }

private:
    bool traversal(TreeNode *left, TreeNode *right) {
        if (left && right) {
            if (left->val != right->val) return false;
            bool outer_res = traversal(left->left, right->right);
            bool inner_res = traversal(left->right, right->left);
            return outer_res && inner_res;
        } else if (!left && !right) {
            return true;
        } else {
            return false;
        }
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto l2_1 = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    auto l2_2 = new TreeNode(2, new TreeNode(4), new TreeNode(3));
    auto l1 = new TreeNode(1, l2_1, l2_2);

    bool rel = true;
    IC(solution->isSymmetric(l1) == rel);

    deleteTreeNode(l1);

    // code end

    return 0;
}


